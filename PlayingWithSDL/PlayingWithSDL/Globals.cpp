#include "Globals.h"
#include <algorithm>
#include <cctype>
#include <SDL_image.h>
#include "Object.h"

SDL_Window* g_Window = nullptr;
SDL_Surface* g_WindowSurface = nullptr;
SDL_Renderer* g_Renderer = nullptr;

std::vector<std::shared_ptr<Sprite>> g_Sprites;

std::vector<std::shared_ptr<Object>> g_ActiveObjects;

bool quit = false;

//Red 0xFF3333
Point3D<float> red = Point3D<float>(0xFF, 0x33, 0x33);

//Blue 0x5cd6d6
Point3D<float> blue = Point3D<float>(0x5C, 0xD6, 0xD6);

//Green 0x5cd65c
Point3D<float> green = Point3D<float>(0x5C, 0xD6, 0x5C);

//the current color of the background
Point3D<float> CurrentColor = red;

int nextColor = 0;

//Are keys down? [0] = this frame, [1] = last frame
std::map<SDL_Keycode, std::pair<bool, bool>> KEYS;

//Gets the file extension of a path
std::string GetFileExtention(std::string path)
{
	std::string extension = path.substr(path.find_last_of('.') + 1);
	std::transform(extension.begin(), extension.end(), extension.begin(), [](unsigned char c) { return std::tolower(c); });
	return extension;
}