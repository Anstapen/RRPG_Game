#include "TitleScreen.h"
#include "olcPixelGameEngine.h"
#include "AnimatedGameTile.h"
#include "StaticGameTile.h"
#include "BGLayer.h"
#include "GUILayer.h"

/*test*/

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

TitleScreen::TitleScreen(std::string name) : 
	State(name)
{
}

State::StateChanger TitleScreen::Execute(float fElapsedTime)
{
	State::StateChanger returnState = State::StateChanger::NO_CHANGE;
	
	for (auto l : this->Layers) {
		l->Update(fElapsedTime);
	}
	/*Update Behavior of all Objects*/

	/* Check if "New Game" Button has been released*/
	/*if (this->NewGameButton->GetState() == Button::ButtonState::BUTTON_RELEASED) {
		returnState = State::StateChanger::BUTTON_NEW_GAME;
	}*/
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

	/*temp int variable to store the layer IDs*/
	int lay_id = 0;
	
	/*Adding the GUI Layer*/
	lay_id = pge->CreateLayer();
	/*Create GUI Layer instance and add it to the Layers list*/
	std::shared_ptr<GUILayer> title_gui = std::make_shared<GUILayer>(lay_id);
	this->Layers.push_back(title_gui);

	/* Adding the Background Layer*/
	lay_id = pge->CreateLayer();
	std::shared_ptr<BGLayer> title_background = std::make_shared<BGLayer>(lay_id, pge->ScreenWidth(), pge->ScreenHeight(), "./gfx/titlescreen_bg.png");
	this->Layers.push_back(title_background);

	/*Temporary Packing Manager Pointer*/
	std::shared_ptr<LayerPM> manager;

	/*Add the Specified Objects to the Layers, based on their Packing value*/
	for (auto l : this->Layers) {
		/*Get the correct Packing Manager for the Layer*/
		manager = l->GetLayerPM();
		/*Use the Packing Manager to populater the Layer*/
		manager->PackLayer(l);
		/*After that, Enable the Layer*/
		l->EnableLayer();
	}
	

	/*Starting TitleScreen Music*/
	std::cout << "Starting Title Music...\n";
	PlaySound(TEXT("./music/TITLESCREEN.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	
	return true;
}

void TitleScreen::DrawContent(float fElapsedTime)
{
	/*Clear Screen to Transparent*/
	//pge->DrawDecal(olc::vf2d(0.0f, 0.0f), this->Transparent.get()->Decal());
	//this->BackGround->Draw(fElapsedTime);
	pge->Clear(olc::BLANK);

	//pge->SetDrawTarget(test_layer);
	//pge->Clear(olc::WHITE);
	//pge->SetPixelMode(olc::Pixel::ALPHA);
	//pge->DrawDecal({ 0,0 }, test->Decal());
	//pge->SetPixelMode(olc::Pixel::NORMAL);
	//pge->SetDrawTarget(nullptr);
	
	//std::cout << "size: " << this->AllObjects.size() << " \n";
	/*Clear the Screen for now...*/
	//this->pge->Clear(NULL);
	/*Draw every object in the AllObjects list*/
	for (auto l : this->Layers) {
		l->Draw(fElapsedTime);
	}
}

void TitleScreen::ChangeState(int state_id)
{
}
