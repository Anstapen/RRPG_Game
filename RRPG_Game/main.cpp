#define OLC_PGE_APPLICATION
#include "Game.h"
#include <iostream>
#include <Windows.h>

int main(void) {
	std::cout << "Starting Game...\n";
	Game game;
	if (game.Construct(960, 576, 2, 2)) {
		//SetCursor(NULL);
		ShowCursor(false);
		game.Start();
	}
	return 0;
}