#include "Sprite.h"

Sprite::Sprite(std::string path) : Path(path)
{
	//Load our image into our surface
	Surface = nullptr;
	LoadImage(Path);

	location.x = 0;
	location.y = 0;

	Rect.x = location.x;
	Rect.y = location.y;
	Rect.w = width;
	Rect.h = height;

	dirty = false;

	g_Sprites.push_back(std::shared_ptr<Sprite>(this));
}

Sprite::Sprite()
{
	//set our path to empty
	Path = "Empty.bmp";
	location.x = 0;
	location.y = 0;
	width = 100;
	height = 100;
	Rect.x = location.x;
	Rect.y = location.y;
	Rect.w = width;
	Rect.h = height;

	Surface = nullptr;
	LoadImage(Path);

	dirty = false;

	g_Sprites.push_back(std::shared_ptr<Sprite>(this));
}

void Sprite::LoadImage(std::string path)
{
	//set our sprite's path to the new path being passed
	if (path != Path)
		Path = path;

	//Load the BMP into our surface
	Surface = SDL_LoadBMP(path.c_str());
	if (Surface == nullptr)
	{
		std::cout << "Error! Could not load file at path: " << Path << std::endl;
		std::string e(SDL_GetError());
		std::cout << "Error is: " << e;
		throw e;
	}

	width = Surface->w;
	height = Surface->h;
}

Sprite::~Sprite()
{
	if(Surface != nullptr)
		SDL_FreeSurface(Surface);
}

void Sprite::Update()
{
	if (dirty)
	{
		Rect.x = location.x;
		Rect.y = location.y;
		Rect.w = width;
		Rect.h = height;

		dirty = false;
	}
}

void Sprite::Draw()
{
	//blit our image to the screen
	SDL_BlitSurface(Surface, NULL, SDL_GetWindowSurface(g_Window), &Rect);
}

int Sprite::GetHeight()
{
	return height;
}

int Sprite::GetWidth()
{
	return width;
}

Point2D<int> Sprite::GetLocation()
{
	return location;
}

void Sprite::SetHeight(int h)
{
	height = h;
	dirty = true;
}

void Sprite::SetWidth(int w)
{
	width = w;
	dirty = true;
}

void Sprite::SetLocation(Point2D<int> loc)
{
	location = loc;
	dirty = true;
}

void Sprite::SetLocation(int x, int y)
{
	location.x = x;
	location.y = y;

	dirty = true;
}