#pragma once
#include "State.h"
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