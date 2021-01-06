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

StateChanger TitleScreen::Execute(float fElapsedTime)
{
	StateChanger returnState = StateChanger::NO_CHANGE;
	
	/*Update all the Layers using the Elapsed Time.
	  The Layers are able to issue a State Change, in this Example with a click on the "New Run" Button*/
	for (auto l : this->Layers) {
		returnState = l->Update(fElapsedTime);
	}
	return returnState;
}

std::string TitleScreen::GetStateStringFromChanger(StateChanger state)
{
	switch (state) {
	case StateChanger::BUTTON_NEW_GAME:
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
	pge->Clear(olc::BLANK);
	
	/*Draw every object in the AllObjects list*/
	for (auto l : this->Layers) {
		l->Draw(fElapsedTime);
	}
}

void TitleScreen::ChangeState(int state_id)
{
}
