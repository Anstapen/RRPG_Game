#pragma once
#include "State.h"
#include "GameObject.h"
#include "Button.h"
#include "Cursor.h"
#include "Layer.h"
#include "StateType.h"

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

protected:
	std::list<std::shared_ptr<Layer>> Layers;
};