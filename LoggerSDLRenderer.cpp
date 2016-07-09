#include "LoggerSDLRenderer.h"
#include <iostream>

using namespace std;

LoggerSDLRenderer::LoggerSDLRenderer(std::string windowTitle, int width, int height):
	_windowTitle(windowTitle),
	_width(width),
	_height(height),
	_wasQuit(false)
{
}

bool LoggerSDLRenderer::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return false;
	}

	_window = SDL_CreateWindow("Hello World!", 100, 100, GetWidth(), GetHeight(), SDL_WINDOW_SHOWN);
	if (_window == nullptr) {
		cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr) {
		SDL_DestroyWindow(_window);
		cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	
	_redSquareTexture = LoadTextureFromBMP("redsquare.bmp");

	return true;
}

void LoggerSDLRenderer::Clear()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}

void LoggerSDLRenderer::DrawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void LoggerSDLRenderer::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void LoggerSDLRenderer::Present()
{
	SDL_RenderPresent(_renderer);
}

SDL_Texture * LoggerSDLRenderer::LoadTextureFromBMP(std::string fileName)
{
	SDL_Surface *bmp = SDL_LoadBMP(fileName.c_str());
	if (bmp == nullptr) {
		cout << "bitmap failed to load " << endl;
		return nullptr;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, bmp);
	SDL_FreeSurface(bmp);
	return texture;
	return nullptr;
}

void LoggerSDLRenderer::DrawRedSquare(int x, int y)
{
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = 256;
	destRect.h = 256;

	SDL_RenderCopy(_renderer, _redSquareTexture, NULL, &destRect);

}
