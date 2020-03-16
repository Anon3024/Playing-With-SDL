#pragma once
#include "Globals.h"
#include "Component.h"

class Object
{
public:
	Object(std::string Name) : name(Name) {};
	~Object() {};

	void DispatchMessage(Message* msg);
	void ProcessMessageQueue();

	void AddComponent(std::shared_ptr<Component> newComp);
private:
	std::string name;
	//a list of all the components attached to this object
	std::vector<std::shared_ptr<Component>> ComponentList;
	//a list of all the messages we need to process
	std::vector<std::shared_ptr<Message>> MessageList;
	
	//a list of all objects that we consider a child
	std::vector<std::shared_ptr<Object>> Children;
};