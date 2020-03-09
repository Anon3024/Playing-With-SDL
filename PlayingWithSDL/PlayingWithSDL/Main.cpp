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

#include "Close.h"
#include "Sprite.h"


void main()
{
	try
	{
		init();
	}
	catch (std::string e)
	{
		std::cout << e << std::endl;
		return;
	}
	Sprite* emptySprite = new Sprite("Empty.png");

	//pause the program
	while (!quit) 
	{
		Update();
		Draw();
	};

	Close();

	return;
}