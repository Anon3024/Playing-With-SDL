#pragma once
#include <SDL_image.h>
#include "Globals.h"
#include "Points.h"
#include "Keys.h"

//A Picture to render. Origin defaults to top left
class Sprite
{
public:
	Sprite(std::string path);
	Sprite();
	~Sprite();

	void LoadImage(std::string path);
	void Update();
	void Draw();

	int GetHeight();
	int GetWidth();
	Point2D<float> GetLocation();

	void SetWidth(int w);
	void SetHeight(int h);
	void SetLocation(Point2D<float> loc);
	void SetLocation(int x, int y);

	//this will evenutally allow for tinting a sprite
	Point3D<Uint8> Color;
private:
	SDL_Rect Rect;
	std::string Path;
	SDL_Texture* Texture;

	int height;
	int width;
	Point2D<float> location;

	bool dirty;
};