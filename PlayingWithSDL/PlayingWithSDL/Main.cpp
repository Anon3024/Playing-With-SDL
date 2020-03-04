//SDL functions
#include <SDL.h>
#undef main
//Memeory Manager 
#include "MemoryManager.h"
#include "SmartPointer.h"
//Standard Includes
#include <string>
#include <iostream>

//Window Dimensions
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

void main()
{
	//The window that we are creating
	SDL_Window* window = nullptr;

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
		window = SDL_CreateWindow("Playing with SDL", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			std::cout << "Error! Could not make window!" << std::endl;
			std::string e = SDL_GetError();
			throw e;
		}
		else
		{
			//Get the surface of the window
			surface = SDL_GetWindowSurface(window);

			//Fill the screen with a color
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x33, 0x33));

			//Update the window
			SDL_UpdateWindowSurface(window);

			//pause the program
			while (true) {};
		}
	}
}