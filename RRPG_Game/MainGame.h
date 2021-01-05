#pragma once
#include "State.h"
class MainGame :
	public State
{
public:
	MainGame(std::string name);
	virtual State::StateChanger Execute(float fElaspedTime) override;
	virtual std::string GetStateStringFromChanger(StateChanger state) override;
	virtual bool Setup() override;
	virtual void DrawContent(float fElapsedTime) override;
};

