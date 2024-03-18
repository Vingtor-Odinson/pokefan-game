#include"Game.hpp"

const int FPS = 30;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[]){

	Uint32 frameStart, frameTime;

	TheGame::Instance()->Init("Teste da Classe Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
	
	while(TheGame::Instance()->Running())
	{

		frameStart = SDL_GetTicks();

		TheGame::Instance()->HandleEvents();
		TheGame::Instance()->Update();
		TheGame::Instance()->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameTime < DELAY_TIME)
		{
			SDL_Delay((int) ( DELAY_TIME - frameTime ));
		}

	}

	TheGame::Instance()->Close();

	return 0;
}