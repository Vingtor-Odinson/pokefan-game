#include"InputHandler.hpp"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler* InputHandler::Instance()
{
	if(s_pInstance == 0)
	{
		s_pInstance = new InputHandler();
	}

	return s_pInstance;
}

void InputHandler::update()
{
	m_keystate = SDL_GetKeyboardState(0);
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if(m_keystate != 0){ //Se o array do estado das teclas estiver correto

		if(m_keystate[key] == 1)
		{
			return true; //Caso a tecla esteja pressionada 
		}

		else
		{
			return false; //Caso a tecla não esteja pressionada
		}

	}

	return false;
}