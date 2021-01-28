#include "Game.h"
#include "TitleScreen.h"
#include "MainGame.h"
#include "DebugState.h"
#include "Debug.h"
#include "MultiTexture.h"

#pragma comment(lib, "User32.lib")

Game::Game()
{
}

/*Test vars*/
MultiTexture* test;

bool Game::OnUserCreate()
{
	/*Test of the new MultiTexture Class*/
	test = new MultiTexture;
	test->AddTexture("char");


	///*Fill the StateList manually, because there should not be that many States*/
	//std::unique_ptr<State> title = std::make_unique<TitleScreen>(StateType::TITLESCREEN);
	//std::unique_ptr<State> maingame = std::make_unique<MainGame>(StateType::MAIN_GAME);
	//std::unique_ptr<State> debug_screen = std::make_unique<DebugState>(StateType::DEBUG);
	//
	///*Push all the created states in the list*/
	//this->StateList.push_back(std::move(title));
	//this->StateList.push_back(std::move(maingame));
	//this->StateList.push_back(std::move(debug_screen));
	//


	///*Execute Setup for each State*/
	//for (int i = 0; i < (int)this->StateList.size(); i++) {
	//	this->StateList[i].get()->Setup();
	//}



	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{

	this->Clear(olc::WHITE);
	olc::vf2d mouse_pos = {(float)this->GetMouseX(), (float)this->GetMouseY()};

	/*do it with simple checks for now*/
	if (this->GetKey(olc::W).bHeld) {
		test->SetState("char", "walking_north");
	}
	else if (this->GetKey(olc::A).bHeld) {
		test->SetState("char", "walking_west");
	}
	else if (this->GetKey(olc::S).bHeld) {
		test->SetState("char", "walking_south");
	}
	else if (this->GetKey(olc::D).bHeld) {
		test->SetState("char", "walking_east");
	}
	else {
		test->SetState("char", "idle");
	}
	test->Draw(fElapsedTime, mouse_pos);
	
//	/*Execute current State of the Game*/
//	StateType returnState = this->StateList[this->iCurrentState].get()->Execute(fElapsedTime);
//
//	/*Draw everything of the current State*/
//	this->DrawCurrentState(fElapsedTime);
//
//
//
//	/*determine which state gets executed in the next frame, depending on the return value.*/
//	if (returnState != StateType::NO_CHANGE) {
//
//		/* Get the index of the next state in the list from the state type*/
//		unsigned int new_index = this->GetNextStateIndex(returnState);
//		std::cout << "State Changed to " <<  ", index: " << new_index << "!\n";
//
//		/*Invoking the OnDisable Function of the current State*/
//		this->StateList[this->iCurrentState]->OnDisable();
//
//		/*Change the current state*/
//		this->iCurrentState = new_index;
//
//		/*Invoking the OnEnable Function of the new State*/
//		this->StateList[this->iCurrentState]->OnEnable();
//	}
//
//	/*All the debug stuff...*/
//#ifdef DEBUG_GAME
//	/*Check for F12 to print Debug info*/
//	if (this->GetKey(olc::Key::F12).bReleased) {
//		std::cout << "Objects created so far: " << debug_obj->nGameObjects << std::endl;
//		std::cout << "Objects copied so far: " << debug_obj->nObjectCopies << std::endl;
//	}
//#endif // DEBUG_GAME

	return true;
}

unsigned int Game::GetNextStateIndex(StateType state)
{
	/*Iterate through the list and search for the state with the correct type
	TODO: the state type is unique... so we do not need to search for it, just use it as vector index...*/
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