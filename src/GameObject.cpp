#include<GameObject.hpp>

void GameObject::load(int x_pos, int y_pos, int width, int height, std::string Id_Texture)
{
	m_x = x_pos;
	m_y = y_pos;

	m_textW = width;
	m_textH = height;

	m_textureId = Id_Texture;

	m_currentRow = 1;
	m_currentCollumn = 1;
}

void GameObject::draw(SDL_Renderer* m_Renderer)
{
	TheTextureManager::Instance()->drawFrame(m_textureId, 0, 0, 14, 22, m_currentRow, m_currentCollumn, m_Renderer, m_x, m_y, m_textW, m_textH);
}