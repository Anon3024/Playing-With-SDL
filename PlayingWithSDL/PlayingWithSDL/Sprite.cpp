#include "Sprite.h"

Sprite::Sprite(std::string path) : Path(path)
{
	//Load our image into our surface
	Texture = nullptr;
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

	//set our color to white
	Color = Point3D<Uint8>(0xFF, 0xFF, 0xFF);

	Texture = nullptr;
	LoadImage(Path);

	dirty = false;

	g_Sprites.push_back(std::shared_ptr<Sprite>(this));
}

void Sprite::LoadImage(std::string path)
{
	//set our sprite's path to the new path being passed
	if (path != Path)
		Path = path;

	//Load our image into an optimized surface
	SDL_Surface* tempSurface = nullptr;

	std::string extension = GetFileExtention(path);

	//if we are loading a bmp
	if (extension == "bmp")
	{
		//Load the BMP into our surface
		tempSurface = SDL_LoadBMP(path.c_str());
		if (tempSurface == nullptr)
		{
			std::cout << "Error! Could not load file at path: " << Path << std::endl;
			std::string e(SDL_GetError());
			std::cout << "Error is: " << e << std::endl;
			throw e;
		}
	}
	//otherwise, if loading a png or jpg
	if (extension == "jpg" || extension == "jpeg" || extension == "png")
	{
		tempSurface = IMG_Load(path.c_str());
		if (tempSurface == nullptr)
		{
			std::cout << "Error! Could not load file at path: " << Path << std::endl;
			std::string e(IMG_GetError());
			std::cout << "Error is: " << e << std::endl;
			throw e;
		}
	}
	
	if (tempSurface == nullptr)
	{
		std::cout << "Error! Could not load file at path: " << Path << std::endl;
		std::string e(SDL_GetError());
		std::cout << "Error is: " << e << std::endl;
		throw e;
	}
	//SDL_PixelFormat_RGBA32 gives us tranparancy
	tempSurface = SDL_ConvertSurfaceFormat(tempSurface, SDL_PIXELFORMAT_RGBA32, 0);
	if (tempSurface == nullptr)
	{
		std::cout << "Error! Could not optimize image!" << std::endl;
		std::string e(SDL_GetError());
		std::cout << "Error is:" << e << std::endl;
		throw e;
	}
	//create a texture from out tempSurface
	Texture = SDL_CreateTextureFromSurface(g_Renderer, tempSurface);
	if (Texture == nullptr)
	{
		std::cout << "Error! Could not create Texture!" << std::endl;
		std::string e(SDL_GetError());
		std::cout << "Error is: " << e << std::endl;
		throw e;
	}

	width = tempSurface->w;
	height = tempSurface->h;

	SDL_FreeSurface(tempSurface);

	SDL_SetTextureBlendMode(Texture, SDL_BLENDMODE_BLEND);
}

Sprite::~Sprite()
{
	if(Texture != nullptr)
		SDL_DestroyTexture(Texture);
}

void Sprite::Update()
{
	float Speed = 1; 

	if (KeyDown(SDLK_UP))
		SetLocation(location.x, location.y - (1 * Speed));
	if (KeyDown(SDLK_DOWN))
		SetLocation(location.x, location.y + (1 * Speed));
	if (KeyDown(SDLK_LEFT))
		SetLocation(location.x - (1 * Speed), location.y);
	if (KeyDown(SDLK_RIGHT))
		SetLocation(location.x + (1 * Speed), location.y);
	if (KeyDown(SDLK_w))
		SetHeight(height - 1);
	if (KeyDown(SDLK_s))
		SetHeight(height + 1);
	if (KeyDown(SDLK_a))
		SetWidth(width - 1);
	if (KeyDown(SDLK_d))
		SetWidth(width + 1);

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
	//SDL_BlitScaled(Surface, NULL, SDL_GetWindowSurface(g_Window), &Rect);
	//Render a texture and not a surface you fool
	SDL_RenderCopy(g_Renderer, Texture, NULL, &Rect);
}

int Sprite::GetHeight()
{
	return height;
}

int Sprite::GetWidth()
{
	return width;
}

Point2D<float> Sprite::GetLocation()
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

void Sprite::SetLocation(Point2D<float> loc)
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