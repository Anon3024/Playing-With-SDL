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
#include "Object.h"


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
	std::shared_ptr<Object> object(new Object("Sprite"));
	object->AddComponent(std::shared_ptr<Sprite>(new Sprite));
	g_ActiveObjects.push_back(object);

	//pause the program
	while (!quit) 
	{
		Update();
		Draw();
	};

	Close();

	return;
}