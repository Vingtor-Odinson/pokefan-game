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

	void load(int x_pos, int y_pos, int width, int height, std::string Id_Texture);

	void draw(SDL_Renderer* m_Renderer);

	void update();

	void clean();

};

#endif