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

#include "Initialize.h"
#include "Update.h"
#include "Draw.h"


void main()
{
	init();
	
	//pause the program
	while (!quit) 
	{
		Update();
		Draw();
	};
			
	//Destory our window
	SDL_DestroyWindow(g_Window);

	//Quit SDL
	SDL_Quit();

	return;
}