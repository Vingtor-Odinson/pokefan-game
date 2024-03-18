#ifndef __GAME_OBJECT__

#define __GAME_OBJECT__

#include<TextureManager.hpp>

class GameObject{

protected:

	int m_x;
	int m_y;

	int m_textW;
	int m_textH;

	int m_currentRow;
	int m_currentCollumn;

	std::string m_textureId;

public:

	virtual void draw(SDL_Renderer* m_Renderer);

	virtual void update();

	virtual void clean();

};

#endif