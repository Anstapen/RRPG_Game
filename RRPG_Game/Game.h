#pragma once
#include "olcPixelGameEngine.h"
#include <memory>
#include "State.h"
#include "StateType.h"

/**********************************************************************************************//**
 * \class	Game
 *
 * \brief	The Foundation Class that inherits from the PixelGameEngine.
 *
 * \author	Anton
 * \date	12.01.2021
 **************************************************************************************************/

class Game : public olc::PixelGameEngine
{
public:
	Game();

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

private:
	
	/** \brief	List of States the Game can be in. */
	std::vector<std::unique_ptr<State>> StateList;

	
	/** \brief	The index of the current State in the StateList. */
	unsigned int iCurrentState = 0;

private:
	/**********************************************************************************************//**
	 * \fn	unsigned int Game::GetNextStateIndex(std::string name);
	 *
	 * \brief	Get the Index of the StateList from the given name
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 *
	 * \param 	name	The name of the state.
	 *
	 * \returns	The index of the given state in the StateList.
	 **************************************************************************************************/
	unsigned int GetNextStateIndex(StateType state);

	/**********************************************************************************************//**
	 * \fn	void Game::DrawCurrentState(float fElapsedTime);
	 *
	 * \brief	Draws the current State on the Screen.
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 *
	 * \param 	fElapsedTime	The elapsed time since the last function call in seconds.
	 **************************************************************************************************/

	void DrawCurrentState(float fElapsedTime);
};

