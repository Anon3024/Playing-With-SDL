#pragma once
#include <SDL.h>
#include <vector>
#include "Sprite.h"
#include <memory>
#include "Lerp.h"
#include "Keys.h"
#include <string>

//Window Dimensions
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Sprite;

//Globals.cpp
extern SDL_Window* g_Window;
extern SDL_Surface* g_WindowSurface;
extern SDL_Renderer* g_Renderer;
extern std::vector<std::shared_ptr<Sprite>> g_Sprites;

extern Point3D<float> red;
extern Point3D<float> blue;
extern Point3D<float> green;

extern Point3D<float> CurrentColor;

extern int nextColor;

extern bool quit;

extern std::map<SDL_Keycode, std::pair<bool, bool>> KEYS;

std::string GetFileExtention(std::string path);