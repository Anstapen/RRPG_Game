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
	std::unique_ptr<State> title = std::make_unique<TitleScreen>(StateType::TITLESCREEN);
	std::unique_ptr<State> maingame = std::make_unique<MainGame>(StateType::MAIN_GAME);
	std::unique_ptr<State> debug_screen = std::make_unique<DebugState>(StateType::DEBUG);
	

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
	StateType returnState = this->StateList[this->iCurrentState].get()->Execute(fElapsedTime);

	/*Draw everything of the current State*/
	this->DrawCurrentState(fElapsedTime);



	/*determine which state gets executed in the next frame, depending on the return value.
	  TODO: Find a better Way to do this, instead of using string compare...*/
	if (returnState != StateType::NO_CHANGE) {
		/* newState contains the name*/
		unsigned int new_index = this->GetNextStateIndex(returnState);
		std::cout << "State Changed to " <<  ", index: " << new_index << "!\n";

		/*Invoking the OnDisable Function of the current State*/
		this->StateList[this->iCurrentState]->OnDisable();
		this->iCurrentState = new_index;
		/*Invoking the OnEnable Function of the new State*/
		this->StateList[this->iCurrentState]->OnEnable();
	}
	//Clear(olc::WHITE);
	
	return true;
}

unsigned int Game::GetNextStateIndex(StateType state)
{
	for (int i = 0; i < (int)this->StateList.size(); i++) {
		if (this->StateList[i].get()->Type == state) {
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