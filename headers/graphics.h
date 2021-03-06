/* Graphics class.
 * Holds all information dealing with graphics for the game.
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

// Forward Declaration of SDL (allows using SDL Pointers without including SDL yet)
// SDL will be included in the source files
struct SDL_Window;
struct SDL_Renderer;

class Graphics
{

public:
	Graphics();
	~Graphics();

	/* SDL_Surface* LoadImage
	 * Loads an image into the m_spriteSheets map if it doesn't already exist.
	 * As a result, each image will only ever be loaded once.
	 * Returns the image from the map regardless of wheter or not it was just loaded.
	 */
	SDL_Surface* loadImage(const std::string &filePath);

	/* void blitSurface
	 * Draws a texture to a certain part of the screen.
	 */
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void flip
	 * Renders everything on the screen.
	 */
	void flip();

	/* void clear
	 * Clears the screen.
	 */
	void clear();

	/* SDL_Renderer* getRenderer
	 * Returns the Renderer.
	 */
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer; // defines what will be drawn onto the window
	std::map<std::string, SDL_Surface*> m_spriteSheets; // holds every spritesheet of the game to make sure to not load spritesheets twice

};

#endif
