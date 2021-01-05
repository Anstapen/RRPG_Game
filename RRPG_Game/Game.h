#pragma once
#include "olcPixelGameEngine.h"
#include <memory>
#include "State.h"
class Game : public olc::PixelGameEngine
{
public:
	Game();

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

private:
	/*The List of States that the Game can have.
	  Using unique Poiners because no one else should have Access to those State Objects!!*/
	std::vector<std::unique_ptr<State>> StateList;

	/*The index of the current State in the StateList*/
	unsigned int iCurrentState = 0;

	/*Resolve the State index of the State with the name <name>*/
	unsigned int GetNextStateIndex(std::string name);

	/* This Routine draws every Object that the current State contains*/
	void DrawCurrentState(float fElapsedTime);
};

