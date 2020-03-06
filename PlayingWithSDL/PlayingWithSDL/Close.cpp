#include "Close.h"

void Close()
{
	//Free our active surfaces
	while(g_Sprites.size() > 0)
	{
		g_Sprites.erase(g_Sprites.begin());
	}
	//Destory our window
	SDL_DestroyWindow(g_Window);

	//Quit SDL
	SDL_Quit();
}