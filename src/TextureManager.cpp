#include"TextureManager.hpp"

TextureManager* TextureManager::c_pTextMan = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	/***
	 * Cria uma textura baseada no arquivo fileName, no pRenderer e com id id
	 ***/

	SDL_Surface* temp_pSurface = IMG_Load(fileName.c_str()); // 
	
	SDL_Texture* c_pTexture = SDL_CreateTextureFromSurface(pRenderer, temp_pSurface);

	SDL_FreeSurface(temp_pSurface);

	if(c_pTexture != 0)
	{
		m_textureMap[id.c_str()] = c_pTexture;
		return true;
	}

	//Smt went wrong

	return false;
}

void TextureManager::draw(std::string id, int x_src, int y_src, int w_src, int h_src, SDL_Renderer* pRenderer, int x_dst, int y_dst, int w_dst, int h_dst, SDL_RendererFlip flip)
{

	/***
	 * 
	 * Desenha o pedaço de textura (id) na posição (x_src, y_src), com tamanho
	 * (w, h) = (w_src, h_src) no renderer pRenderer na posição (x_dst, y_dst)
	 * com tamanho (w, h) = (w_dst, h_dst) e com possível flip
	 * 
	 ***/

	SDL_Rect m_srcRect;
	SDL_Rect m_dstRect;

	if(w_dst == -1){
		w_dst = w_src;
	}
	if(h_dst == -1){
		h_dst = h_src;
	}

	m_srcRect.x = x_src;
	m_srcRect.y = y_src;
	m_srcRect.w = w_src;
	m_srcRect.h = h_src;

	m_dstRect.x = x_dst;
	m_dstRect.y = y_dst;
	m_dstRect.w = w_dst;
	m_dstRect.h = h_dst;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id.c_str()], &m_srcRect, &m_dstRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x_src, int y_src, int w_src, int h_src, int currentRow, int currentCollumn, SDL_Renderer* pRenderer, int x_dst, int y_dst, int w_dst, int h_dst, SDL_RendererFlip flip)
{
	/***
	 * 
	 * Desenha o frame em (currentRow, currentCollumn) 
	 * da textura (id) na posição (x_src, y_src), com tamanho
	 * (w, h) = (w_src, h_src) no renderer pRenderer na posição (x_dst, y_dst)
	 * com tamanho (w, h) = (w_dst, h_dst) e com possível flip
	 * 
	 ***/


	SDL_Rect m_srcRect;
	SDL_Rect m_dstRect;

	if(w_dst == -1){
		w_dst = w_src;
	}
	if(h_dst == -1){
		h_dst = h_src;
	}

	m_srcRect.x = x_src + w_src*(1-currentCollumn);
	m_srcRect.y = y_src + h_src*(1-currentRow);
	m_srcRect.w = w_src;
	m_srcRect.h = h_src;

	m_dstRect.x = x_dst;
	m_dstRect.y = y_dst;
	m_dstRect.w = w_dst;
	m_dstRect.h = h_dst;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id.c_str()], &m_srcRect, &m_dstRect, 0, 0, flip);
}

TextureManager* TextureManager::Instance()
{
	if(c_pTextMan == 0)
	{
		c_pTextMan = new TextureManager();
	}
	return c_pTextMan;
}