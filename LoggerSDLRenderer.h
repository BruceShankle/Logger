#pragma once
#include <SDL.h>
#include <string>
class LoggerSDLRenderer {
public:
	LoggerSDLRenderer(std::string windowTitle, int width, int height);
	bool Initialize();
	int GetWidth() { return _width; }
	int GetHeight() { return _height; }
	void Clear();
	void DrawLine(int x1, int y1, int x2, int y2);
	void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void Present();

protected:
	std::string _windowTitle;
	int _width;
	int _height;
	bool _wasQuit;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};