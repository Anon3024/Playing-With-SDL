#include "Object.h"

void Object::DispatchMessage(Message* msg)
{
	//add a new pointer to the back of our message list
	MessageList.push_back(std::shared_ptr<Message>(msg));

	//Dispatch the message to each of our children
	for (std::shared_ptr<Object> c : Children)
	{
		c->DispatchMessage(msg);
	}
}

void Object::ProcessMessageQueue()
{
	//for each message in our message queue
	for (std::shared_ptr<Message> msg : MessageList)
	{
		//for each component in each our component list
		for (std::shared_ptr<Component> comp : ComponentList)
		{
			comp->ReceiveMessage(msg.get());
		}
	}
	//After checking giving every compoent each message in our list, clear our list
	MessageList.clear();
}

void Object::AddComponent(std::shared_ptr<Component> newComp)
{
	this->ComponentList.push_back(newComp);
}