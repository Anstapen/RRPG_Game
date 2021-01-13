#pragma once


/*This is the main define to enable the debug stuff of the game.*/
#ifndef DEBUG_GAME
#define DEBUG_GAME
#endif // !DEBUG_GAME


class Debug
{
public:
	void printObjectCopies();
public:
	int nGameObjects = 0;
	int nObjectCopies = 0;
};


/*show the debug obj to the rest of the sources*/
#ifdef DEBUG_GAME
extern Debug* debug_obj;
#endif