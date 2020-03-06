#include "Update.h"
#include "Globals.h"
#include "Keys.h"

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

	for (std::pair<SDL_Keycode, std::pair<bool, bool>> k : KEYS)
	{
		std::cout << k.second.first << "," << k.second.second << std::endl;
	}

	for (std::shared_ptr<Sprite> sprite : g_Sprites)
	{
		sprite->Update();
	}
}