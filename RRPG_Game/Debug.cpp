#include "Debug.h"
#include <iostream>


#ifdef DEBUG_GAME
Debug* debug_obj = new Debug();
#endif

void Debug::printObjectCopies()
{
	std::cout << "DEBUG Number of Object copies so far: " << this->nObjectCopies << std::endl;
}

void Debug::Print(std::string s)
{
	std::cout << "DEBUG: " << s << std::endl;
}