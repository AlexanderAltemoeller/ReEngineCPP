//============================================================================
// Name        : main.cpp
// Author      : Alexander Altemoeller
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <SDL2/SDL.h>

#include "game.h"

int main(int argc, char* argv[])
{
	// Force stdout to be line-buffered (needed to make printf work, due to an eclipse bug <.<)
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("%s\n", "Hi!");

	Game game;

    return 0;
}
