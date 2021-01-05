#include "TitleScreen.h"
#include "olcPixelGameEngine.h"
#include "AnimatedGameTile.h"
#include "StaticGameTile.h"

/*test*/

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

TitleScreen::TitleScreen(std::string name) : State(name)
{
}

State::StateChanger TitleScreen::Execute(float fElapsedTime)
{
	State::StateChanger returnState = State::StateChanger::NO_CHANGE;
	
	for (std::shared_ptr<GameObject> b : this->AllObjects) {
		b->Update(fElapsedTime);
	}
	/*Update Behavior of all Objects*/

	/* Check if "New Game" Button has been released*/
	if (this->NewGameButton->GetState() == Button::ButtonState::BUTTON_RELEASED) {
		returnState = State::StateChanger::BUTTON_NEW_GAME;
	}
	return returnState;
}

std::string TitleScreen::GetStateStringFromChanger(StateChanger state)
{
	switch (state) {
	case State::StateChanger::BUTTON_NEW_GAME:
		return "MainGame";
		break;
	default:
		return "TitleScreen";
		break;
	}
}

/*This is called once in OnUserCreate() to setup up the basic objects*/
bool TitleScreen::Setup()
{
	std::cout << "Executing Setup Routine for TitleScreen...\n";
	std::cout << "Adding Objects...\n";
	
	
	/* Adding one Leaf per Tile*/
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 12; y++) {
			this->AllObjects.push_back(std::make_shared<AnimatedGameTile>("./gfx/Leaf.png", 4, false, olc::vf2d(x+0.5f, y+0.5f), false));
		}
	}

	/*Add TitleScreen Buttons*/

	/*Add the "New Game" Button*/
	std::shared_ptr<Button> start_button = std::make_shared<Button>("./gfx/NewGame_Button-Sheet.png", 50, 20, olc::vf2d(pge->ScreenWidth() / 2, ((pge->ScreenHeight() * 2) / 3)));
	//std::shared_ptr<Button> test_button = std::make_shared<Button>("./gfx/Test_Button.png", 50, 20, olc::vf2d(pge->ScreenWidth() / 2, ((pge->ScreenHeight() * 2) / 3)-70));
	this->AllObjects.push_back(start_button);
	//this->AllObjects.push_back(test_button);

	this->AllButtons.push_back(start_button);
	//this->AllButtons.push_back(test_button);

	this->NewGameButton = start_button;


	/*Adding the Main Cursor*/
	std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Sword_Cursor-Sheet.png", 56, 56, olc::vf2d(0.25f, 0.25f));
	this->AllObjects.push_back(main_cursor);
	this->MainCursor = main_cursor;

	std::cout << "Finished Adding Objects.\n";
	std::cout << "Amount of Objects added: " << this->AllObjects.size() << " \n";

	/*Starting TitleScreen Music*/
	std::cout << "Starting Title Music...\n";
	PlaySound(TEXT("./music/TITLESCREEN.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	return true;
}

void TitleScreen::DrawContent(float fElapsedTime)
{
	//std::cout << "size: " << this->AllObjects.size() << " \n";
	/*Clear the Screen for now...*/
	this->pge->Clear(olc::WHITE);
	/*Draw every object in the AllObjects list*/
	for (std::shared_ptr<GameObject> p : this->AllObjects) {
		p->Draw(fElapsedTime);
	}
	for (int x = 0; x < pge->ScreenWidth() / 24; x++) {
		for (int y = 0; y < pge->ScreenHeight() / 24; y++) {
			pge->DrawRect(x * 24, y * 24, 24, 24, olc::BLACK);
		}
		
	}

}
