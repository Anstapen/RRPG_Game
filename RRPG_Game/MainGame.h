#pragma once
#include "State.h"

/**********************************************************************************************//**
 * \class	MainGame
 *
 * \brief	The main game state. The game will be in this state for the most time. This State
 * 			contains all the game logic, the map and some gui elements.
 *
 * \author	Anton
 * \date	13.01.2021
 **************************************************************************************************/

class MainGame :
	public State
{
public:
	MainGame(StateType in_type);
	virtual StateType Execute(float fElaspedTime) override;
	virtual bool Setup() override;
	virtual void DrawContent(float fElapsedTime) override;
	virtual void OnEnable() override;
	virtual void OnDisable() override;
};