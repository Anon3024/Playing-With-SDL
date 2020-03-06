#pragma once
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
	Point2D<int> GetLocation();

	void SetWidth(int w);
	void SetHeight(int h);
	void SetLocation(Point2D<int> loc);
	void SetLocation(int x, int y);

private:
	SDL_Rect Rect;
	std::string Path;
	SDL_Surface* Surface;

	int height;
	int width;
	Point2D<int> location;

	bool dirty;
};