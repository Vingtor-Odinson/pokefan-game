#include"Player.hpp"

void Player::load(float x_pos, float y_pos, int width, int height, std::string Id_Texture)
{
	m_position.setX(x_pos);
	m_position.setY(y_pos);

	m_textW = width;
	m_textH = height;

	m_textureId = Id_Texture;

	m_currentRow = 1;
	m_currentCollumn = 1;
}

void Player::draw(SDL_Renderer* m_Renderer)
{
	GameObject::draw(m_Renderer);
}

void Player::update()
{	
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_position.setX( m_position.getX() + 10 );
	}
	else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_position.setX( m_position.getX() - 10 );
	}
	else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{	
		m_position.setY( m_position.getY() - 10 );
	}
	else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{	
		m_position.setY( m_position.getY() + 10 );
	}



	m_currentRow = int((SDL_GetTicks() / 200)%3) - 1;
}

void Player::clean()
{
}