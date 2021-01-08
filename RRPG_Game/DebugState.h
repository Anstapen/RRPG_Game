#pragma once
#include "State.h"
#include "SimplePoly.h"
class DebugState :
	public State
{
public:
	DebugState(std::string name);
	virtual StateChanger Execute(float fElapsedTime) override;
	virtual std::string GetStateStringFromChanger(StateChanger state) override;
	virtual bool Setup() override;
	virtual void DrawContent(float fElapsedTime) override;
	virtual void ChangeState(int state_id) override;
	virtual void OnEnable() override;
	virtual void OnDisable() override;
};