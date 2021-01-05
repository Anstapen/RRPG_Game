#define OLC_PGE_APPLICATION
#include "Game.h"
#include <iostream>
#include <Windows.h>

int main(void) {
	std::cout << "Starting Game...\n";
	Game game;
	if (game.Construct(480, 288, 4, 4)) {
		//SetCursor(NULL);
		ShowCursor(false);
		game.Start();
	}
	return 0;
}