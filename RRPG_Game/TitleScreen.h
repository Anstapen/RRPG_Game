#pragma once
#include "State.h"
#include "GameObject.h"
#include "Button.h"
#include "Cursor.h"

class TitleScreen :
	public State
{
public:
	TitleScreen(std::string name);
	virtual State::StateChanger Execute(float fElapsedTime) override;
	virtual std::string GetStateStringFromChanger(StateChanger state) override;
	virtual bool Setup() override;
	virtual void DrawContent(float fElapsedTime) override;

public:
	std::list<std::shared_ptr<GameObject>> AllObjects;
	std::list<std::shared_ptr<Button>> AllButtons;
	std::shared_ptr<Cursor> MainCursor = nullptr;
	std::shared_ptr<Button> NewGameButton;
};

