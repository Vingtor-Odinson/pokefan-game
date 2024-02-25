#include<Game.hpp>

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
	
	int Window_w = SDL_GetWindowSurface(g_pwindow)->w;
	int Window_h = SDL_GetWindowSurface(g_pwindow)->h;
	int Text_w = int(Window_w*160/640);
	int Text_h = int(Window_h*160/480);

	TheTextureManager::Instance()->load("res/Brendan.png", "BrendanWalk", g_prenderer); //Uses the Texture Manager to read the image and create a texture

	TheTextureManager::Instance()->drawFrame("BrendanWalk", 0, 0, 14, 22, m_currentFrame, 1, g_prenderer, (Window_w - Text_w)/2, (Window_h - Text_h)/2, Text_w, Text_h); //Draw the actual frame

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
	m_currentFrame = int((SDL_GetTicks() / 200)%3) - 1;
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