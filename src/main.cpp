#include"Game.hpp"

Game* game;

int main(int argc, char* args[]){

	game = new Game();

	game->Init("Teste da Classe Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
	
	while(game->Running())
	{

		game->HandleEvents();
		game->Update();
		game->Render();

	}

	game->Close();

	return 0;
}