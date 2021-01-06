#pragma once
#include "State.h"
#include "GameObject.h"
#include "Button.h"
#include "Cursor.h"
#include "Layer.h"

class TitleScreen :
	public State
{
public:
	TitleScreen(std::string name);
	virtual StateChanger Execute(float fElapsedTime) override;
	virtual std::string GetStateStringFromChanger(StateChanger state) override;
	virtual bool Setup() override;
	virtual void DrawContent(float fElapsedTime) override;
	virtual void ChangeState(int state_id) override;

protected:
	std::list<std::shared_ptr<Layer>> Layers;
};