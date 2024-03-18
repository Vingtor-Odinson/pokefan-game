#ifndef __GAME_CLASS__
#define __GAME_CLASS__

#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"TextureManager.hpp"

#include"GameObject.hpp"
#include"Player.hpp"
#include"InputHandler.hpp"

class Game{

private:
	bool c_bRunning;
	SDL_Window* g_pwindow = NULL;
	SDL_Renderer* g_prenderer = NULL;

	TextureManager* g_TextMan;	
	int m_currentFrame;

	Player m_player1;
	Player m_player2;

	Game(){}

public:

	bool Init(const char* title, int x, int y, int width, int height, Uint32 flags);
	
	bool Running();

	void Update();
	
	void HandleEvents();
	
	void Render();
	
	void Close();

	static Game* Instance();

	SDL_Renderer* getRenderer();

	static Game* c_pInstance;

};

typedef Game TheGame;

#endif