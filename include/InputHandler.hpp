#ifndef __INPUT_HANDLER__
#define __INPUT_HANDLER__

#include<SDL2/SDL.h>

class InputHandler{

private:

	static InputHandler* s_pInstance;
	const Uint8* m_keystate;
	InputHandler(){}
	~InputHandler(){}	

public:

	static InputHandler* Instance();

	void update();

	bool isKeyDown(SDL_Scancode key);

	void clean();

};

typedef InputHandler TheInputHandler; 

#endif