/* Graphics class.
 * Holds all information dealing with graphics for the game.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
	//&this->m_window is exactly &m_window
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->m_window, &this->m_renderer);
	SDL_SetWindowTitle(this->m_window, "Texture Loading Demo");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->m_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
	// if the spritesheet has not been loaded yet
	if(this->m_spriteSheets.count(filePath) == false)
	{
		this->m_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}

	return this->m_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->m_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->m_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->m_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->m_renderer;
}
