#include <iostream>
#include "LoggerSDLRenderer.h"

int main(int argc, char *args[]) {
	LoggerSDLRenderer* pRenderer = new LoggerSDLRenderer("Logger", 640, 480);
	pRenderer->Initialize();

	int x1 = 0;
	int x2 = pRenderer->GetWidth();
	int y1 = 0;
	int y2 = pRenderer->GetHeight();
	bool descending = true;

	SDL_Event e;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_KEYDOWN) {
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				quit = true;
			}
		}

		pRenderer->Clear();
	
		if (descending) {
			y1++;
			y2--;
		}
		else {
			y1--;
			y2++;
		}
		if (y1 == pRenderer->GetHeight()+1 || y1==-1) {
			descending = !descending;
		}
		
		pRenderer->SetColor(255, 255, 255, 255);
		pRenderer->DrawLine(x1, y1, x2, y2);
		pRenderer->Present();
	}
	

	SDL_Quit();
	return 0;
}

