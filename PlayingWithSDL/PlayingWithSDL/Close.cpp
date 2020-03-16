#include "Close.h"
#include "Globals.h"


void Close()
{
	//Free our active surfaces
	while(g_Sprites.size() > 0)
	{
		g_Sprites.erase(g_Sprites.begin());
	}
	//Destroy our renderer
	SDL_DestroyRenderer(g_Renderer);
	//Destroy our window
	SDL_DestroyWindow(g_Window);

	//Quit SDL
	SDL_Quit();
}