#include "Draw.h"
#include <string>
#include <iostream>

void Draw()
{
	//filling the background with some colors
	switch (nextColor)
	{
	case 0:
		CurrentColor = Lerp(CurrentColor, blue, 0.0006);
		if (isAbout(CurrentColor, blue))
			++nextColor;
		break;
	case 1:
		CurrentColor = Lerp(CurrentColor, green, 0.0006);
		if (isAbout(CurrentColor, green))
			++nextColor;
		break;
	case 2:
		CurrentColor = Lerp(CurrentColor, red, 0.0006);
		if (isAbout(CurrentColor, red))
			nextColor = 0;
	}
	SDL_Surface* windowSurface = SDL_GetWindowSurface(g_Window);
	SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, CurrentColor.x, CurrentColor.y, CurrentColor.z));

	for (std::shared_ptr<Sprite> sprite : g_Sprites)
	{
		sprite->Draw();
	}
	SDL_UpdateWindowSurface(g_Window);
}