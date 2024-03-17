#ifndef __GAME_OBJECT__

#define __GAME_OBJECT__

#include<TextureManager.hpp>
#include"Vector2.hpp"

class GameObject{

protected:

	Vector2 m_position = Vector2(0.0f, 0.0f);

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