#include<GameObject.hpp>

void GameObject::draw(SDL_Renderer* m_Renderer)
{
	TheTextureManager::Instance()->drawFrame(m_textureId, 0.0f, 0.0f, 14, 22, m_currentRow, m_currentCollumn, m_Renderer, m_position.getX(), m_position.getY(), m_textW, m_textH);
}

void GameObject::update()
{
}

void GameObject::clean()
{
}