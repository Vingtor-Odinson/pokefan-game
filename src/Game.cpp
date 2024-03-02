#include<Game.hpp>

Game* Game::c_pInstance = 0;

bool Game::Init(const char* title, int x, int y, int width, int height, Uint32 flags)
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) >= 0)
	{
		//The SDL could successfully be initiated, let's init the window
		
		g_pwindow = SDL_CreateWindow( title, x, y, width, height, flags );

		if(g_pwindow != 0){

			g_prenderer = SDL_CreateRenderer(g_pwindow, -1, 0);
		}

		else{
			printf("The window could not be initiated!");
			std::cin.get();
			return false;
		}

	}
	
	else{
		printf("The SDL could not be initiated!");
		std::cin.get();
		return false;
	}

	c_bRunning = true;

	TheTextureManager::Instance()->load("res/Brendan.png", "BrendanWalk", g_prenderer); //Uses the Texture Manager to read the image and create a texture

	m_player1.load(300, 0, 70, 110, "BrendanWalk");
	m_player2.load(200, 0, 70, 110, "BrendanWalk");

	return true;
}

bool Game::Running()
{
	return c_bRunning;
}

void Game::Render()
{
	SDL_SetRenderDrawColor( g_prenderer, 255, 255, 255, 255);

	SDL_RenderClear(g_prenderer); //Clear the window to black

	m_player1.draw(g_prenderer);
	m_player2.draw(g_prenderer);

	SDL_RenderPresent(g_prenderer); //Show the window
}

void Game::Close()
{	

	SDL_DestroyWindow(g_pwindow);
	SDL_DestroyRenderer(g_prenderer);
	SDL_Quit();
}

void Game::Update()
{
	m_player1.update();
	m_player2.update();
}

void Game::HandleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch (event.type){
			case SDL_QUIT:
				c_bRunning = false;
			break;

			default:
			break;
		}
	}
}

Game* Game::Instance()
{
	if( c_pInstance == 0 ){
		c_pInstance = new Game();
	}

	return c_pInstance;
}

SDL_Renderer* Game::getRenderer()
{
	return g_prenderer;
}