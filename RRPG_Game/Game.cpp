#include "Game.h"
#include "TitleScreen.h"
#include "MainGame.h"
#include "DebugState.h"

#pragma comment(lib, "User32.lib")

Game::Game()
{
}

bool Game::OnUserCreate()
{
	/*Fill the StateList manually, because there should not be that many States*/
	std::unique_ptr<State> title = std::make_unique<TitleScreen>("TitleScreen");
	std::unique_ptr<State> maingame = std::make_unique<MainGame>("MainGame");
	std::unique_ptr<State> debug_screen = std::make_unique<DebugState>("DebugScreen");

	this->StateList.push_back(std::move(title));
	this->StateList.push_back(std::move(maingame));
	this->StateList.push_back(std::move(debug_screen));


	/*Execute Setup for each State*/
	for (int i = 0; i < (int)this->StateList.size(); i++) {
		this->StateList[i].get()->Setup();
	}
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	
	/*Execute current State of the Game*/
	StateChanger returnState = this->StateList[this->iCurrentState].get()->Execute(fElapsedTime);

	/*Draw everything of the current State*/
	this->DrawCurrentState(fElapsedTime);



	/*determine which state gets executed in the next frame, depending on the return value.
	  TODO: Find a better Way to do this, instead of using string compare...*/
	if (returnState != StateChanger::NO_CHANGE) {
		/* newState contains the name*/
		std::string newState = this->StateList[this->iCurrentState].get()->GetStateStringFromChanger(returnState);
		unsigned int new_index = this->GetNextStateIndex(newState);
		std::cout << "State Changed to " << newState << ", index: " << new_index << "!\n";

		/*Invoking the OnDisable Function of the current State*/
		this->StateList[this->iCurrentState]->OnDisable();
		this->iCurrentState = new_index;
		/*Invoking the OnEnable Function of the new State*/
		this->StateList[this->iCurrentState]->OnEnable();
	}
	
	return true;
}

unsigned int Game::GetNextStateIndex(std::string name)
{
	for (int i = 0; i < (int)this->StateList.size(); i++) {
		if (this->StateList[i].get()->sName == name) {
			return i;
		}
	}
	return 0;
}

void Game::DrawCurrentState(float fElapsedTime)
{
	/*Draw all objects of the current State*/
	this->StateList[this->iCurrentState].get()->DrawContent(fElapsedTime);
}