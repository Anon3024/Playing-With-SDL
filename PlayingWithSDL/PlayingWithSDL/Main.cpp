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

#include "Lerp.h"
#include "Points.h"

void main()
{
	//The window that we are creating
	extern SDL_Window* g_Window;

	//The surface of our window
	SDL_Surface* surface = nullptr;

	Point2D<int> a;
	std::cout << a;

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

			//Red 0xFF3333
			Point3D<float> red = Point3D<float>(0xFF, 0x33, 0x33);

			//Blue 0x5cd6d6
			Point3D<float> blue = Point3D<float>(0x5C, 0xD6, 0xD6);

			//Green 0x5cd65c
			Point3D<float> green = Point3D<float>(0x5C, 0xD6, 0x5C);

			//Fill the screen with a color
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, red.x, red.y, red.z));

			//Update the window
			SDL_UpdateWindowSurface(g_Window);

			Point3D<float> currentColor = red;
			int color = 0;

			//pause the program
			while (true) 
			{
				//Lerp our color
				if (color == 0)
				{
					currentColor = Lerp(currentColor, blue, 0.001);
					if (isAbout(currentColor, blue))
						++color;
				}
				if (color == 1)
				{
					currentColor = Lerp(currentColor, green, 0.001);
					if (isAbout(currentColor, green))
						++color;
				}
				if (color == 2)
				{
					currentColor = Lerp(currentColor, red, 0.001);
					if (isAbout(currentColor, red))
						color = 0;
				}
					

				//Fill the screen with a color
				SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, currentColor.x, currentColor.y, currentColor.z));

				//Update the window
				SDL_UpdateWindowSurface(g_Window);
			};
		}
	}
}