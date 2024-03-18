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
	m_currentRow = int((SDL_GetTicks() / 200)%3) - 1;
}

void Player::clean()
{
}