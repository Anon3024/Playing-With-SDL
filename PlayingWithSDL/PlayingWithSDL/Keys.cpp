#include "Keys.h"

void UpdateKey(SDL_Keycode key, bool state)
{
	//key at this frame is set to state
	KEYS[key].first = state;
}

void UpdateAllKeys()
{
	for (std::pair<SDL_Keycode, std::pair<bool, bool>> k : KEYS)
	{
		//set state last frame equal to value this frame
		KEYS[k.first].second = k.second.first;
	}
}

bool KeyPressed(SDL_Keycode key)
{
	//if key is down this frame, but not last frame
	return (KEYS[key].first && !KEYS[key].second);
}

bool KeyDown(SDL_Keycode key)
{
	//if key is down this frame and last fram
	return (KEYS[key].first && KEYS[key].second);
}

bool KeyReleased(SDL_Keycode key)
{
	//if key is up this frame, and not last frame
	return (!KEYS[key].first && KEYS[key].second);
}

bool KeyUp(SDL_Keycode key)
{
	//if key is up this frame and last fram
	return (!KEYS[key].first && !KEYS[key].second);
}