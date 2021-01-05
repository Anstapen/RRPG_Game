#pragma once
#include <string>
#include "olcPixelGameEngine.h"
/*This is the abstract State class.
  Every possible State the Game is in inherits from this class.
 */
class State : public olc::PGEX
{
public:
	enum class StateChanger {
		NO_CHANGE = 0,
		KEY_ESCAPE =  1,
		KEY_ENTER = 2,
		BUTTON_NEW_GAME = 1000
	};
public:
	std::string sName;

public:
	State(std::string name);
	virtual ~State();
	virtual StateChanger Execute(float fElapsedTime) = 0;
	virtual std::string GetStateStringFromChanger(StateChanger state) = 0;
	virtual bool Setup() = 0;
	virtual void DrawContent(float fElapsedTime) = 0;
};

