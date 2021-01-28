#pragma once
#include <string>
#include <iostream>
/*This is the main define to enable the debug stuff of the game.*/
#ifndef DEBUG_GAME
#define DEBUG_GAME
#endif // !DEBUG_GAME

/*DEBUG print on standart out*/
#ifdef DEBUG_GAME
#define DEBUG_PRINT(msg) do { Debug::Print(msg); } while(0)
#else
#define DEBUG_PRINT(msg)
#endif // !DEBUG_GAME


class Debug
{
public:
	void printObjectCopies();
	static void Print(std::string s);
public:
	int nGameObjects = 0;
	int nObjectCopies = 0;
};


/*show the debug obj to the rest of the sources*/
#ifdef DEBUG_GAME
extern Debug* debug_obj;
#endif