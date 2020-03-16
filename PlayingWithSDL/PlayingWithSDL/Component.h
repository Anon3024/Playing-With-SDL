#pragma once
#pragma message ("Component Defined")
#include "Globals.h"
#include "Message.h"
#include "Listener.h"
#include <memory>
#include <functional>

//Takes a message, and a member function. This member function takes a message* and returns void
//This creates a new listener, that calls func upon receiving msg
#define connect(msg, func)\
	{\
		std::function<void(Message*)> fn;\
		fn = [this](Message* m) { func(m); };\
		this->ConnectMessage(msg, fn);\
	}

//The compnent class is a class that all componets will inherit from
class Component
{
public:
	Component(std::string Name) : name(Name) {}
	//The initialize function must be defined by every single inherited class
	virtual void Initialize() = 0;
	std::string GetName() { return name; };

	//associates a given fuction with a listener
	void ConnectMessage(Message* msg, std::function<void(Message*)> fn);
	void ReceiveMessage(Message* msg);
private:
	std::vector<std::shared_ptr<Listener>> Listeners;
	std::string name;
};