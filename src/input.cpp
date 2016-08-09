/* Input class.
 * Keeps track of keyboard state.
 */

#include "input.h"

// This function gets called at the beginning of each new frame
// to reset the keys that are no longer relevant
void Input::beginNewFrame()
{
	this->m_pressedKeys.clear();
	this->m_releasedKeys.clear();
}

// This function gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event &event)
{
	this->m_pressedKeys[event.key.keysym.scancode] = true;
	this->m_heldKeys[event.key.keysym.scancode] = true;
}

// This function gets called when a key is released
void Input::keyUpEvent(const SDL_Event &event)
{
	this->m_releasedKeys[event.key.keysym.scancode] = true;
	this->m_heldKeys[event.key.keysym.scancode] = false;
}

// Check if a certain key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key)
{
	return this->m_pressedKeys[key];
}

// Check if a certain key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key)
{
	return this->m_releasedKeys[key];
}

// Check if a certain key is currently being held
bool Input::isKeyHeld(SDL_Scancode key)
{
	return this->m_heldKeys[key];
}
