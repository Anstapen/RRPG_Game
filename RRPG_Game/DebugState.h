#pragma once
#include "State.h"
#include "SimplePoly.h"
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