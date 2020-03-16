#pragma once
#include "Globals.h"
#include <functional>

class Listener
{
public:
	Listener(std::string message) : call(message) {};
	~Listener() {};

	bool CheckMessage(Message* msg) { return msg->GetMessage() == call; };

	std::function<void(Message*)> response;
private:
	std::string call;
	
};