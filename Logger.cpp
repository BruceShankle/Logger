#include <iostream>
#include "LoggerSDLRenderer.h"
#include "Frog.h"
using namespace std;

int main(int argc, char *args[]) {
	LoggerSDLRenderer* pRenderer = new LoggerSDLRenderer("Logger", 1024, 768);
	if (!pRenderer->Initialize()) {
		cout << "Renderer could not initialize." << endl;
		return -1;
	}
	Frog* pFrog = new Frog();
	pFrog->SetVelocity(20, 100);

	int x1 = 0;
	int x2 = pRenderer->GetWidth();
	int y1 = 0;
	int y2 = pRenderer->GetHeight();
	bool descending = true;

	SDL_Event e;
	bool quit = false;
	Uint32 lastTicks = 0;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		Uint32 ticks = SDL_GetTicks();
		if (lastTicks > 0) {
			double elapsedTime = (ticks - lastTicks) / 1000.0;
			pFrog->Update(elapsedTime);
			pRenderer->Clear();

			if (descending) {
				y1++;
				y2--;
			}
			else {
				y1--;
				y2++;
			}
			if (y1 == pRenderer->GetHeight() + 1 || y1 == -1) {
				descending = !descending;
			}

			pRenderer->SetColor(255, 255, 255, 255);
			pRenderer->DrawLine(x1, y1, x2, y2);
			pRenderer->DrawRedSquare(pFrog->GetPosition().x, pFrog->GetPosition().y);
			Position frogPosition = pFrog->GetPosition();

			if (frogPosition.x < 0 || frogPosition.x > pRenderer->GetWidth()-256) {
				pFrog->ReverseX();
			}
			if (frogPosition.y < 0 || frogPosition.y > pRenderer->GetHeight()-256) {
				pFrog->ReverseY();
			}

			pRenderer->Present();
		}
		lastTicks = ticks;	
	}
	

	SDL_Quit();
	return 0;
}

