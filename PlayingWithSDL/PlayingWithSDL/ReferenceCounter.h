#pragma once

class ReferenceCounter 
{
public:
	ReferenceCounter();

	void AddReference();
	void ReleseCount();
	
	int GetCount();
private:
	int Count;
};

ReferenceCounter::ReferenceCounter() : Count(0)
{
}

void ReferenceCounter::AddReference()
{
	++Count;
}

void ReferenceCounter::ReleseCount()
{
	--Count;
}

int ReferenceCounter::GetCount()
{
	return Count;
}