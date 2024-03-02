#include"Game.hpp"

int main(int argc, char* args[]){

	TheGame::Instance()->Init("Teste da Classe Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
	
	while(TheGame::Instance()->Running())
	{

		TheGame::Instance()->HandleEvents();
		TheGame::Instance()->Update();
		TheGame::Instance()->Render();

	}

	TheGame::Instance()->Close();

	return 0;
}