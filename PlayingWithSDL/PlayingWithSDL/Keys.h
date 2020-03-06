#pragma once
#include <map>
#include "Globals.h"

void UpdateKey(SDL_Keycode key, bool state);
void UpdateAllKeys();

bool KeyPressed(SDL_Keycode key);
bool KeyDown(SDL_Keycode key);
bool KeyReleased(SDL_Keycode key);
bool KeyUp(SDL_Keycode key);