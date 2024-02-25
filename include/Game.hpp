#ifndef __GAME_CLASS__
#define __GAME_CLASS__

#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"TextureManager.hpp"

typedef TextureManager TheTextureManager;

class Game{

private:
	bool c_bRunning;
	SDL_Window* g_pwindow = NULL;
	SDL_Renderer* g_prenderer = NULL;

	TextureManager* g_TextMan;	
	int m_currentFrame;

public:

	bool Init(const char* title, int x, int y, int width, int height, Uint32 flags);
	
	bool Running();

	void Update();
	
	void HandleEvents();
	
	void Render();
	
	void Close();

};

#endif