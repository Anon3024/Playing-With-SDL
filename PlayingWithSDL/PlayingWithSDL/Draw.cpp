#include "Draw.h"
#include "Lerp.h"
#include "Sprite.h"
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
	SDL_SetRenderDrawColor(g_Renderer, CurrentColor.x, CurrentColor.y, CurrentColor.z, 255);
	//SDL_Surface* windowSurface = SDL_GetWindowSurface(g_Window);
	//SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, CurrentColor.x, CurrentColor.y, CurrentColor.z));
	SDL_RenderClear(g_Renderer);
	for (std::shared_ptr<Sprite> sprite : g_Sprites)
	{
		sprite->Draw();
	}
	SDL_RenderPresent(g_Renderer);
	//SDL_UpdateWindowSurface(g_Window);
}