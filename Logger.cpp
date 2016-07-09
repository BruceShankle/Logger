#include <iostream>
#include <SDL.h>
int main(int argc, char *args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//Create an SDL Window
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	//Create an SDL Renderer
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	int x1 = 0;
	int x2 = 640;
	int y1 = 0;
	int y2 = 480;
	bool descending = true;
	while (true) {
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		if (descending) {
			y1++;
			y2--;
		}
		else {
			y1--;
			y2++;
		}
		if (y1 == 481 || y1==-1) {
			descending = !descending;
		}
		
		SDL_SetRenderDrawColor(ren, y1, 255, y2, 255);
		SDL_RenderDrawLine(ren,
			x1, y1, x2, y2);
		SDL_RenderPresent(ren);
	}
	SDL_Delay(5000);

	SDL_Quit();
	return 0;
}

