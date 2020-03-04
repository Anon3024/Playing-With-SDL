//SDL functions
#include <SDL.h>
#undef main
//Memeory Manager 
#include "MemoryManager.h"
#include "SmartPointer.h"
//Our Global Files
#include "Globals.h"
//Standard Includes
#include <string>
#include <iostream>

void main()
{
	//The window that we are creating
	extern SDL_Window* g_Window;

	//The surface of our window
	SDL_Surface* surface = nullptr;

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
		else
		{
			//Get the surface of the window
			surface = SDL_GetWindowSurface(g_Window);

			//Fill the screen with a color
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x33, 0x33));

			//Update the window
			SDL_UpdateWindowSurface(g_Window);

			//pause the program
			while (true) {};
		}
	}
}