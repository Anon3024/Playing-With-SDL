#pragma once
#include "ReferenceCounter.h"
#include "MemoryManager.h"


/*
* A pointer that uses reference counting. Expects to work with MemoryManager.h
*/
template <typename T>
class SmartPointer
{
public:
	SmartPointer(MemoryManager<T>* manager);
	SmartPointer(T* p, MemoryManager<T>* manager);
	SmartPointer(const SmartPointer<T>& p);
	~SmartPointer();

	T& operator*();
	T* operator->();
	SmartPointer<T>& operator=(const SmartPointer<T>& other);
	SmartPointer<T>& operator=(T* const& other);
	bool operator==(const T* other);

	operator T* () const;

	int GetReferences();
private:
	T* Data;
	ReferenceCounter* Counter;
	MemoryManager<T>* Manager;
};

//Constructor, Make a new reference counter
template <typename T>
SmartPointer<T>::SmartPointer(MemoryManager<T>* manager) : Manager(manager)
{
	Counter = new ReferenceCounter();
	Counter->AddReference();
	Data = nullptr;
}

//Constructor, from data pointer
template <typename T>
SmartPointer<T>::SmartPointer(T* p, MemoryManager<T>* manager) : Manager(manager)
{
	Counter = new ReferenceCounter();
	Counter->AddReference();
	Data = p;
}

//Copy constructor, use shallow copies to ensure that we're modifiying the same data.
template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& p)
{
	Counter = p.Counter;
	Data = p.Data;
	Counter->AddReference();
	Manager = p.Manager;
}

//Deconstrutor
template <typename T>
SmartPointer<T>::~SmartPointer()
{
	//Lower our count by one
	Counter->ReleseCount();
	//if we are down to 0 count
	if (Counter->GetCount() == 0)
	{
		//Delete our counter
		delete Counter;
		//Delete, or when integrated with the Memeory Manager, Deallocate
		if(Data != nullptr)
			Manager->DeallocateMemory(Data);
	}
}

template <typename T>
T& SmartPointer<T>::operator*()
{
	return *Data;
}

template <typename T>
T* SmartPointer<T>::operator->()
{
	return Data;
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& other)
{
	//Avoid self assignment
	if (&other != this)
	{
		//decriment our current counter
		Counter->ReleseCount();
		if (Counter->GetCount() == 0)
		{
			//do the deletion process here
			delete Counter;
			if(Data != nullptr)
				Manager->DeallocateMemory(Data);
		}
		//copy the reference over
		this->Data = other.Data;
		this->Counter = other.Counter;

		this->Counter->AddReference();
	}
	return *this;
}

template <typename T>
int SmartPointer<T>::GetReferences()
{
	return this->Counter->GetCount();
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(T* const& other)
{
	//decrease the reference counter
	this->Counter->ReleseCount();
	if (Counter->GetCount() == 0)
	{
		//do the deletion process here
		delete Counter;
		if(Data != nullptr)
			Manager->DeallocateMemory(Data);
	}
	//Make a new reference counter to count this unmanaged pointer
	this->Counter = new ReferenceCounter();
	this->Counter->AddReference();
	//store the other
	this->Data = other;
}

template <typename T>
bool SmartPointer<T>::operator==(const T* other)
{
	return this->Data == other;
}

template <typename T>
SmartPointer<T>::operator T* () const
{
	return this->Data;
}