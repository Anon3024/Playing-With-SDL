#include "Component.h"

void Component::ConnectMessage(Message* msg, std::function<void(Message*)> fn)
{
	std::shared_ptr<Listener> lis(new Listener(msg->GetMessage()));
	lis->response = fn;
	this->Listeners.push_back(lis);
}

void Component::ReceiveMessage(Message* msg)
{
	for (std::shared_ptr<Listener> ls : Listeners)
	{
		if (ls->CheckMessage(msg))
			ls->response(msg);
	}
}