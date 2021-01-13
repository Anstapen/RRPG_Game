#pragma once
#include "State.h"

/**********************************************************************************************//**
 * \class	DebugState
 *
 * \brief	This is a debug state that is accessible by a button on the titlescreen. It is used
 * 			to test stuff.
 *
 * \author	Anton
 * \date	13.01.2021
 **************************************************************************************************/

class DebugState :
	public State
{
public:
	DebugState(StateType in_type);
	virtual StateType Execute(float fElapsedTime) override;
	virtual bool Setup() override;
	virtual void DrawContent(float fElapsedTime) override;
	virtual void OnEnable() override;
	virtual void OnDisable() override;
};