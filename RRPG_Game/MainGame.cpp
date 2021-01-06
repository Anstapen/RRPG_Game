#include "MainGame.h"

MainGame::MainGame(std::string name) : State(name)
{
}

StateChanger MainGame::Execute(float fElaspedTime)
{
	StateChanger returnState = StateChanger::NO_CHANGE;


	/* Check if the ENTER Key is released*/
	if (pge->GetKey(olc::Key::ESCAPE).bReleased) {
		returnState = StateChanger::KEY_ESCAPE;
	}
	return returnState;
}

std::string MainGame::GetStateStringFromChanger(StateChanger state)
{
	switch (state) {
	case  StateChanger::KEY_ESCAPE:
		return "TitleScreen";
		break;
	default:
		return "TitleScreen";
		break;
	}
}

bool MainGame::Setup()
{
	return true;
}

void MainGame::DrawContent(float fElapsedTime)
{
	/*Clear the Screen for now...*/
	this->pge->Clear(olc::DARK_BLUE);
}

void MainGame::ChangeState(int state_id)
{
}
