#pragma once
#include <ostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>


template <typename T>
class Block
{
public:
	Block();
	~Block();

	void SetDebug(bool IsDebug);
	void* GetObject();

	void DumpBlock();
	void AllocateBlock();

	void SetUsed(bool used);

	int GetID();
	
	void __SetID(int id);

	friend std::ostream& operator<<(std::ostream& os, Block& b);
private:
	/*************************************************************************
	* A Memory Block consits of a single object, as well as a small handful
	* Of Debug information. See Illustration Below:
	* Key - [ = Open Section
	*     - 1,2,3...N = Expected Number of Bytes
	*	  - X = Varaible Number of Bytes
	*	  - ] = Close Section
	* [1 = In Use][X - Object][10 - Padding Bytes]
	*************************************************************************/
	void* Memory;
	//the size of our object
	const size_t ObjectSize;
	//are we debugging?
	bool Debug;
	//Are we in use?
	bool* isUsed;
	//The object that we are storing
	T* Object;
	//the ID of the page we are on
	int PageId;
};

template <typename T>
Block<T>::Block() : ObjectSize(sizeof(T))
{
	//set the block to null
	this->Memory = nullptr;
	this->Debug = false;
	this->isUsed = nullptr;
	this->Object = nullptr;

	AllocateBlock();
}

template <typename T>
void Block<T>::AllocateBlock()
{
	/*************************************************************************
	* A Memory Block consits of a single object, as well as a small handful
	* Of Debug information. See Illustration Below:
	* Key - [ = Open Section
	*     - 1,2,3...N = Expected Number of Bytes
	*	  - X = Varaible Number of Bytes
	*	  - ] = Close Section
	*[1 = In Use][50 = Debug Chars][X - Object][10 - Padding Bytes]
	*************************************************************************/
	this->Memory = malloc(sizeof(bool) + this->ObjectSize + (sizeof(char) * 10));
	if (Memory == NULL)
	{
		std::string e = "Error! Could not allocate Memory!";
		throw e;
	}
	//set pointers to the various locations in our block
	char* BlockWalker = reinterpret_cast<char*>(this->Memory);
	this->isUsed = reinterpret_cast<bool*>(BlockWalker);
	BlockWalker += sizeof(bool);
	this->Object = reinterpret_cast<T*>(BlockWalker);
	BlockWalker += ObjectSize;
	memset(reinterpret_cast<void*>(BlockWalker), '-', sizeof(char) * 10);

	*this->isUsed = false;
}

template <typename T>
void Block<T>::SetDebug(bool IsDebug)
{
	this->Debug = IsDebug;
}

template <typename T>
void* Block<T>::GetObject()
{
	return this->Object;
}

template <typename T>
void Block<T>::SetUsed(bool used)
{
	*(this->isUsed) = used;
}

template <typename T>
void Block<T>::DumpBlock()
{
	if (this->Memory != nullptr)
	{
		char* BlockWalker = reinterpret_cast<char*>(this->Memory);
		//print if block is currently allocated
		std::cout << "{[" << (*reinterpret_cast<bool*>(BlockWalker) ? "True" : "False") << "]";
		BlockWalker += sizeof(bool);
		//print object this block is holding
		std::cout << "[" << *reinterpret_cast<T*>(BlockWalker) << "]";
		BlockWalker += sizeof(T*);
		//print the padding bytes
		std::cout << "[";
		for (int i = 0; i < sizeof(char) * 10; ++i)
		{
			std::cout << *BlockWalker;
			++BlockWalker;
		}
		std::cout << "]}";
	}
}

template <typename T>
Block<T>::~Block()
{
	if (this->Memory != nullptr)
	{
		free(this->Memory);
		this->Memory = nullptr;
	}
}

template <typename T>
int Block<T>::GetID()
{
	return this->PageId;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Block<T>& b)
{
	return os << &b;
}

template <typename T>
void Block<T>::__SetID(int id)
{
	this->PageId = id;
}