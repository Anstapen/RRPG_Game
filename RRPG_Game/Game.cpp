#include "Game.h"
#include "TitleScreen.h"
#include "MainGame.h"
#include "DebugState.h"
#include "Debug.h"
#include "MultiTexture.h"
#include "EventSystem.h"
#include "ButtonEvent.h"


#include "ButtonListener.h"
#include <chrono>

#pragma comment(lib, "User32.lib")

uint32_t n_events = 100;

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
	test->AddTexture("basic_armor");
    //test->Disable("basic_armor");


	///*Fill the StateList manually, because there should not be that many States*/
	std::unique_ptr<State> title = std::make_unique<TitleScreen>(StateType::TITLESCREEN);
	std::unique_ptr<State> maingame = std::make_unique<MainGame>(StateType::MAIN_GAME);
	std::unique_ptr<State> debug_screen = std::make_unique<DebugState>(StateType::DEBUG);
	//
	///*Push all the created states in the list*/
	this->StateList.push_back(std::move(title));
	this->StateList.push_back(std::move(maingame));
	this->StateList.push_back(std::move(debug_screen));
	//


	///*Execute Setup for each State*/
	for (int i = 0; i < (int)this->StateList.size(); i++) {
		this->StateList[i].get()->Setup();
	}

	/* Setup the EventSystem */
	if (EventSystem::Init() != 0)
	{
		std::cout << "Event System Init failed!" << std::endl;
	}

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	/* Update the EventSystem */
	EventSystem::Update();

	//this->Clear(olc::WHITE);
	olc::vf2d mouse_pos = {(float)this->GetMouseX(), (float)this->GetMouseY()};

	///*Enalbe armor, if space bar is released*/
	//if (this->GetKey(olc::SPACE).bReleased) {
	//	test->Enable("basic_armor");
	//}

	///*Disable armor, if backspace is released*/
	//if (this->GetKey(olc::BACK).bReleased) {
	//	test->Disable("basic_armor");
	//}
	std::unique_ptr<ButtonEvent> event;
	for (uint32_t i = 0; i < n_events; i++)
	{
		event = ButtonEvent::Create(fElapsedTime, Key::W, ButtonEvent::State::RELEASED, 0);

		EventSystem::AddEvent(event.get()->GetGUID(), std::move(event));
	}
	/*do it with simple checks for now*/
	if (this->GetKey(olc::W).bReleased) {
		n_events = n_events * 10;
		std::cout << "Changed Events per Second to: " << n_events << std::endl;
	}
	else if (this->GetKey(olc::A).bHeld) {
		
	}
	else if (this->GetKey(olc::S).bReleased) {
		n_events = n_events / 10;
		std::cout << "Changed Events per Second to: " << n_events << std::endl;
	}
	else if (this->GetKey(olc::D).bHeld) {
		
	}
	ButtonListener::Listen(fElapsedTime);

	//else {
	//	test->SetState("idle");
	//}
	//test->Draw(fElapsedTime, mouse_pos);
	
	/*Execute current State of the Game*/
	StateType returnState = this->StateList[this->iCurrentState].get()->Execute(fElapsedTime);

	/*Draw everything of the current State*/
	this->DrawCurrentState(fElapsedTime);



	/*determine which state gets executed in the next frame, depending on the return value.*/
	if (returnState != StateType::NO_CHANGE) {

		/* Get the index of the next state in the list from the state type*/
		unsigned int new_index = this->GetNextStateIndex(returnState);
		std::cout << "State Changed to " <<  ", index: " << new_index << "!\n";

		/*Invoking the OnDisable Function of the current State*/
		this->StateList[this->iCurrentState]->OnDisable();

		/*Change the current state*/
		this->iCurrentState = new_index;

		/*Invoking the OnEnable Function of the new State*/
		this->StateList[this->iCurrentState]->OnEnable();
	}

	/*All the debug stuff...*/
#ifdef DEBUG_GAME
	/*Check for F12 to print Debug info*/
	if (this->GetKey(olc::Key::F12).bReleased) {
		std::cout << "Objects created so far: " << debug_obj->nGameObjects << std::endl;
		std::cout << "Objects copied so far: " << debug_obj->nObjectCopies << std::endl;
	}
#endif // DEBUG_GAME

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