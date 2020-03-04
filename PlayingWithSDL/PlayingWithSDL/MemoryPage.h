#pragma once
#include "MemoryBlock.h"
#include <list>
#include <iostream>
#include <algorithm>


template <typename T>
class Page 
{
public:
	Page(int id, const unsigned pagesize);
	~Page();

	//Returns a pointer to the next unused block. Will be templated eventually
	T* AllocateBlock();
	//Moves the given pointer to the unused list. Will be templated eventually
	bool DeallocateBlock(T* object);
	//Dumps the page
	void DumpPage();
	//Dumps the used blocks
	void DumpUsed();
	//Dumps the unused blocks
	void DumpUnused();

	//Gets our ID
	int GetID();
private:
	void SetBlockID(Block<T>* block);

	//The array of our memory blocks
	Block<T>* Memory;

	//The list of unused memory blocks
	std::list<Block<T>*> unused;
	//the list of used memory blocks
	std::list<Block<T>*> used;

	//the current size of used memory blocks
	unsigned Size;
	//the ID of our page.
	const int ID;
	//the size of our page
	const unsigned PAGESIZE;
};

template <typename T>
Page<T>::Page(int id, const unsigned pagesize) : ID(id), PAGESIZE(pagesize)
{
	this->Memory = nullptr;
	//Allocate our page
	this->Memory = new Block<T>[PAGESIZE];
	for (unsigned i = 0; i < PAGESIZE; ++i)
	{
		SetBlockID(&this->Memory[i]);
		this->unused.push_back(&this->Memory[i]);
	}
	this->Size = 0;
}

template <typename T>
Page<T>::~Page()
{
	if (this->Memory != nullptr)
		delete[] this->Memory;
	this->Memory = nullptr;
}

template <typename T>
T* Page<T>::AllocateBlock()
{
	if (this->Size == PAGESIZE)
	{
		std::pair<int, std::string> e;
		e.first = 1;
		e.second = "Page size Error! This page is full. Please Allocate on a new page.";

		throw e;
	}
	//Grab the next block off the unused list
	Block<T>* next = this->unused.front();
	this->unused.pop_front();

	//set the Block to used.
	next->SetUsed(true);

	//Add the block to the used list
	this->used.push_back(next);

	//incriment our size
	++(this->Size);

	//return the object pointer
	return reinterpret_cast<T*>(next->GetObject());
}

template <typename T>
bool Page<T>::DeallocateBlock(T* object)
{
	//do we handle this object?
	bool HandleObject = false;
	//the pointer to the block in question
	Block<T>* block = nullptr;
	//Given the pointer, search our list for a block that's holding it
	for (Block<T>* b : this->used)
	{
		if (b->GetObject() == object)
		{
			block = b;
			HandleObject = true;
			break;
		}
	}
	if (block == nullptr)
	{
		HandleObject = false;
		std::string e = "Error, handed unmanaged memory.";
		throw e;
	}

	//set the block to unused
	block->SetUsed(false);

	//add the block to the unused list
	this->unused.push_front(block);

	//remove the block from the used list
	this->used.remove(block);

	//decriment our size
	--(this->Size);

	return HandleObject;
}

template <typename T>
void Page<T>::DumpPage()
{
	std::cout << std::endl;
	for (int i = 0; i < PAGESIZE; ++i)
	{
		this->Memory[i].DumpBlock();
	}
	std::cout << std::endl;
}

template <typename T>
void Page<T>::DumpUsed()
{
	std::cout << std::endl;
	for (Block<T>* b : this->used)
	{
		b->DumpBlock();
	}
	std::cout << std::endl;
}

template <typename T>
void Page<T>::DumpUnused()
{
	std::cout << std::endl;
	for (Block<T>* b : this->unused)
	{
		b->DumpBlock();
	}
	std::cout << std::endl;
}

template <typename T>
void Page<T>::SetBlockID(Block<T>* block)
{
	block->__SetID(this->ID);
}

template <typename T>
int Page<T>::GetID()
{
	return this->ID;
}