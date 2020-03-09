#include <SDL.h>
#include "Initialize.h"
#include "Globals.h"
#include <iostream>

void init()
{
	//intializing SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error! Could not initailize SDL Video!" << std::endl;
		std::string e = SDL_GetError();
		throw e;
	}
	//If we didn't error out, make the window
	else
	{
		//making the window
		g_Window = SDL_CreateWindow("Playing with SDL", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (g_Window == nullptr)
		{
			std::cout << "Error! Could not make window!" << std::endl;
			std::string e = SDL_GetError();
			throw e;
		}
	}

	g_WindowSurface = SDL_GetWindowSurface(g_Window);

	//Set up Keys will have to do all of them going forward
	KEYS[SDLK_w] = std::pair<bool, bool>(false, false);
	KEYS[SDLK_a] = std::pair<bool, bool>(false, false);
	KEYS[SDLK_s] = std::pair<bool, bool>(false, false);
	KEYS[SDLK_d] = std::pair<bool, bool>(false, false);
	KEYS[SDLK_UP] = std::pair<bool, bool>(false, false);
	KEYS[SDLK_LEFT] = std::pair<bool, bool>(false, false);
	KEYS[SDLK_DOWN] = std::pair<bool, bool>(false, false);
	KEYS[SDLK_RIGHT] = std::pair<bool, bool>(false, false);
}