#include "Update.h"
#include "Globals.h"

void Update()
{
	//Check if we've got any SDL events
	SDL_Event Events;

	//Get our SDL_Events
	while (SDL_PollEvent(&Events))
	{
		//if the user wants to close the window
		if (Events.type == SDL_QUIT)
			//close the window.
			quit = true;
	}

	for (std::shared_ptr<Sprite> sprite : g_Sprites)
	{
		sprite->Update();
	}
}