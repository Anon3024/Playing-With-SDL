#include "Update.h"
#include "Globals.h"
#include "Keys.h"
#include "Object.h"

void Update()
{
	//Check if we've got any SDL events
	SDL_Event Events;

	UpdateAllKeys();

	//Get our SDL_Events
	while (SDL_PollEvent(&Events))
	{
		switch (Events.type)
		{
		//if we want to close the window
		case SDL_QUIT:
			//close it!
			quit = true;
			break;
		case SDL_KEYDOWN:
			UpdateKey(Events.key.keysym.sym, true);
			break;
		case SDL_KEYUP:
			UpdateKey(Events.key.keysym.sym, false);
			break;
		}
	}

	for (std::shared_ptr<Object> object : g_ActiveObjects)
	{
		//push the update message to all of our active objects
		object->DispatchMessage(new Message("Update"));
		//then process the messages on all our active objects
		object->ProcessMessageQueue();
	}

	//for (std::shared_ptr<Sprite> sprite : g_Sprites)
	//{
	//	sprite->Update();
	//}
}