#pragma once
#include "Globals.h"
#include <string>

class Message
{
public:
	Message(std::string message) : msg(message) {};
	~Message() {};
	std::string GetMessage() { return msg; };
private:
	std::string msg;
};