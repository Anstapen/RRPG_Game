#pragma once
#include "State.h"
#include "GameObject.h"
#include "Button.h"
#include "Cursor.h"
#include "Layer.h"
#include "StateType.h"

/**********************************************************************************************//**
 * \class	TitleScreen
 *
 * \brief	This is the first state the game gets into. It displays the Titlescreen with a
 * 			background and some GUI elements. It does not introduce any new class mambers, the
 * 			important difference is implemented in the overritten functions.
 *
 * \author	Anton
 * \date	13.01.2021
 **************************************************************************************************/

class TitleScreen :
	public State
{
public:
	TitleScreen(StateType in_type);
	virtual StateType Execute(float fElapsedTime) override;
	virtual bool Setup() override;
	virtual void DrawContent(float fElapsedTime) override;
	virtual void OnEnable() override;
	virtual void OnDisable() override;
};