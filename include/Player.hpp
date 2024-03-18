#ifndef __ENTITY__
#define __ENTITY__

#include<GameObject.hpp>
#include<InputHandler.hpp>

class Player : public GameObject{
	
public:

	void load(float x_pos, float y_pos, int width, int height, std::string Id_Texture);

	void draw(SDL_Renderer* m_Renderer);

	void update();

	void clean();

};

#endif