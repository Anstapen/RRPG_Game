#define OLC_PGE_APPLICATION
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include "Texture.h"

int main(void) {

	/*Short test for json*/





	std::cout << "Starting Game...\n";
	/*TODO: Init code and ressource check*/
	Game game;
	if (game.Construct(960, 576, 2, 2)) {
		//SetCursor(NULL);
		ShowCursor(false);
		game.Start();
	}
	return 0;
	
	

}