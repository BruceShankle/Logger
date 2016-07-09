#include "LoggerSDLRenderer.h"
#include <iostream>

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
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	_window = SDL_CreateWindow("Hello World!", 100, 100, GetWidth(), GetHeight(), SDL_WINDOW_SHOWN);
	if (_window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr) {
		SDL_DestroyWindow(_window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	return false;
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
