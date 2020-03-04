#pragma once
#include <map>
#include <iostream>
#include "MemoryPage.h"


template <typename T>
class MemoryManager
{
public:
	//Takes the size of a page
	MemoryManager(int pageSize);
	~MemoryManager();

	//Allocate a new Block
	T* AllocateMemory();
	//Deallocate a Block
	void DeallocateMemory(T* block);

	//Dump the pages
	void DumpPages();
private:
	//The pages we have, sorted by ID
	std::map<int, Page<T>*> Pages;
	//The size of each of our pages, sorted by ID
	std::map<int, unsigned> PageSize;

	//Allocate a new Page
	Page<T>* CreatePage();

	//the number of pages we currently have
	unsigned PageCount;

	//the number of objects that can be stored on a single page
	const unsigned PAGESIZE;
};

template <typename T>
MemoryManager<T>::MemoryManager(int pageSize) : PAGESIZE(pageSize)
{
	this->PageCount = 0;
	//create a page
	CreatePage();
}

template <typename T>
T* MemoryManager<T>::AllocateMemory()
{
	Page<T>* TargetPage = nullptr;
	for (std::pair<int, unsigned> p : PageSize)
	{
		if (p.second < PAGESIZE)
		{
			TargetPage = Pages[p.first];
			break;
		}
	}
	//if Target Page is still null, then create a new page
	if (TargetPage == nullptr)
		TargetPage = CreatePage();

	++PageSize[TargetPage->GetID()];

	//Allocate a block on the new page
	return TargetPage->AllocateBlock();
}

template <typename T>
void MemoryManager<T>::DeallocateMemory(T* block)
{
	int PagesTried = 0;
	//dont try to delete null duh
	if (block == nullptr || block == NULL)
		return;
	//Walk the list of pages, and see we can delete the block.
	for (std::pair<int, Page<T>*> p : Pages)
	{
		try
		{
			if (p.second->DeallocateBlock(block))
			{
				--this->PageSize[p.first];
				break;
			}
				
		}
		catch (std::string e)
		{
			//The memory is not on this page.
			//Put any handling you want here. Print if debugging.
		}
		++PagesTried;
	}
	if (PagesTried >= static_cast<int>(this->PageCount))
	{
		std::pair<int, std::string> e;
		e.first = -1;
		e.second = "Error! Provided Memory is not being handled by this Manager!";
		throw e;
	}
}

template <typename T>
Page<T>* MemoryManager<T>::CreatePage()
{
	//Make a new page, and update the page counter
	Page<T>* newPage = new Page<T>(++PageCount, PAGESIZE);
	Pages.insert(std::pair<int, Page<T>*>(PageCount, newPage));
	PageSize.insert(std::pair<int, unsigned>(1, 0));
	return newPage;
}

template <typename T>
void MemoryManager<T>::DumpPages()
{
	for (std::pair<int, Page<T>*> p : Pages)
	{
		std::cout << "Dumping Page #" << p.first << std::endl;
		p.second->DumpPage();
	}
}

template <typename T>
MemoryManager<T>::~MemoryManager()
{
	for (std::pair<int, Page<T>*> p : Pages)
	{
		delete p.second;
	}
}