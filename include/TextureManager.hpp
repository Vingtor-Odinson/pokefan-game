#ifndef __TEXTURE_MANAGER__
#define __TEXTURE_MANAGER__

#include<map>
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class TextureManager{

private:
	std::map<std::string, SDL_Texture*> m_textureMap;
	TextureManager(){}


public:

	static TextureManager* c_pTextMan;

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x_src, int y_src, int w_src, int h_src, SDL_Renderer* pRenderer, int x_dst = 0, int y_dst = 0, int w_dst = -1, int h_dst = -1, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x_src, int y_src, int w_src, int h_src, int currentRow, int currentCollumn, SDL_Renderer* pRenderer, int x_dst = 0, int y_dst = 0, int w_dst = -1, int h_dst = -1, SDL_RendererFlip flip = SDL_FLIP_NONE);

	static TextureManager* Instance();
};

typedef TextureManager TheTextureManager;

#endif