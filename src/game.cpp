/*
 * Game class.
 * Holds all information for our main game loop.
 */

#include <algorithm>
#include <SDL2/SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS; // maximum amount of time a frame is allowed to last
}

Game::Game()
{
	// Init every subsystem of SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game()
{

}

// called every frame
void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->m_player = Sprite(graphics, "assets/sprites/MyChar.png", 0, 0, 16, 16, 100, 100);

	int LAST_UPDATE_TIME = SDL_GetTicks(); // Get the number of milliseconds since SDL was initialized

	// start the game loop
	while(true)
	{
		// refresh pressed and released keys
		input.beginNewFrame();

		// check every frame if an event is called
		if(SDL_PollEvent(&event))
		{
			// if a key is pressed down
			if(event.type == SDL_KEYDOWN)
			{
				// make sure that the key is only tapped and not being held down
				if(event.key.repeat == false)
				{
					// safe the pressed key
					input.keyDownEvent(event);
				}
			}
			// if a key is released
			else if(event.type == SDL_KEYUP)
			{
				// release the pressed key in the map of all pressed keys
				input.keyUpEvent(event);
			}
			// if the program ends / the X is clicked, end the program
			else if(event.type == SDL_QUIT)
			{
				return;
			}
		}
		// if escape is pressed, end the program
		if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}

		// Limit FPS to 50 for making sure to grant the same performance on every computer
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();
	this->m_player.draw(graphics, 100, 100);
	graphics.flip();
}

void Game::update(float elapsedtime)
{

}
