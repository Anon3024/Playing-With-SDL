#include "Draw.h"
#include <string>
#include <iostream>

void Draw()
{
	if (BMP == nullptr)
	{
		BMP = SDL_LoadBMP("BMP.bmp");
		if (BMP == nullptr)
		{
			std::cout << "Error! Couldn't load file!" << std::endl;
			std::cout << SDL_GetError() << std::endl;
			std::string e = SDL_GetError();
			throw e;
		}
	}
	SDL_Surface* windowSurface = SDL_GetWindowSurface(g_Window);
	SDL_BlitSurface(BMP, NULL, windowSurface, NULL);
	SDL_UpdateWindowSurface(g_Window);
}