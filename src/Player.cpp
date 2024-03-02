#include"Player.hpp"

void Player::load(int x_pos, int y_pos, int width, int height, std::string Id_Texture)
{
	GameObject::load(x_pos, y_pos, width, height, Id_Texture);
}

void Player::draw(SDL_Renderer* m_Renderer)
{
	GameObject::draw(m_Renderer);
}

void Player::update()
{
	m_currentRow = int((SDL_GetTicks() / 200)%3) - 1;
}