#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL2/SDL.h>

class Input
{

public:
	void beginNewFrame();
	void keyDownEvent(const SDL_Event &event);
	void keyUpEvent(const SDL_Event &event);
	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);

private:
	std::map<char, int> first;
	std::map<SDL_Scancode, bool> m_heldKeys;
	std::map<SDL_Scancode, bool> m_pressedKeys;
	std::map<SDL_Scancode, bool> m_releasedKeys;

};

#endif
