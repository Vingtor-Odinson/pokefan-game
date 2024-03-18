#include<GameObject.hpp>

void GameObject::draw(SDL_Renderer* m_Renderer)
{
	TheTextureManager::Instance()->drawFrame(m_textureId, 0, 0, 14, 22, m_currentRow, m_currentCollumn, m_Renderer, m_x, m_y, m_textW, m_textH);
}

void GameObject::update()
{
}

void GameObject::clean()
{
}