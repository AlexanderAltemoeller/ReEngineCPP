/* Sprite class.
 * Holds all information for individual sprites.
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL.h>

// Forward declare graphics
class Graphics;

class Sprite
{

public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);

private:
	SDL_Rect m_sourceRect;
	SDL_Texture* m_spriteSheet;
	float m_x, m_y;

};

#endif
