#include "MainGame.h"
#include "GUILayer.h"
#include "DebugLayer.h"
#include "BGLayer.h"
#include "TileSet.h"
#include "Map.h"
#include "GameLayer.h"

MainGame::MainGame(std::string name) : State(name)
{
}

StateChanger MainGame::Execute(float fElapsedTime)
{
	StateChanger returnState = StateChanger::NO_CHANGE;


	/*Update all the Layers using the Elapsed Time.
	  The Layers are able to issue a State Change, in this Example with a click on the "New Run" Button*/
	StateChanger tempState;
	for (auto l : this->Layers) {
		tempState = l->Update(fElapsedTime, this->ExternalEvents);
		if (tempState != StateChanger::NO_CHANGE) {
			returnState = tempState;
		}
	}


	/* Check if the ESC Key is released*/
	if (pge->GetKey(olc::Key::ESCAPE).bReleased) {
		returnState = StateChanger::TITLESCREEN;
	}
	return returnState;
}

std::string MainGame::GetStateStringFromChanger(StateChanger state)
{
	switch (state) {
	case  StateChanger::TITLESCREEN:
		return "TitleScreen";
		break;
	default:
		return "MainGame";
		break;
	}
}

bool MainGame::Setup()
{
	std::cout << "Executing Setup Routine for MainGame...\n";
	std::cout << "Adding Objects...\n";

	/*temp int variable to store the layer IDs*/
	int lay_id = 0;

	/*Adding the GUI Layer*/
	lay_id = pge->CreateLayer();
	/*Create GUI Layer instance and add it to the Layers list*/
	std::shared_ptr<GUILayer> maingame_gui = std::make_shared<GUILayer>(lay_id, PackingManager::PackingStyle::MAIN_GAME);
	this->Layers.push_back(maingame_gui);

	/*Adding the Game Layer*/
	lay_id = pge->CreateLayer();
	std::shared_ptr<GameLayer> maingame_game = std::make_shared<GameLayer>(lay_id);

	this->Layers.push_back(maingame_game);

	/* Adding the Background Layer*/
	lay_id = pge->CreateLayer();
	std::shared_ptr<BGLayer> maingame_background = std::make_shared<BGLayer>(lay_id, pge->ScreenWidth(), pge->ScreenHeight(), std::string(), olc::WHITE);

	this->Layers.push_back(maingame_background);


	/*Temporary Packing Manager Pointer*/
	std::shared_ptr<LayerPM> manager;

	/*Add the Specified Objects to the Layers, based on their Packing value*/
	for (auto l : this->Layers) {
		/*Get the correct Packing Manager for the Layer*/
		manager = l->GetLayerPM();
		/*Use the Packing Manager to populater the Layer*/
		manager->PackLayer(l);
		/*Execute the Setup function for each layer*/
		l->Setup();
		/*After that, Enable the Layer*/
		l->EnableLayer();
	}
	/*Clear Layer 0 to Transparent, because this Layer never gets used*/
	pge->Clear(olc::BLANK);
	return true;
}

void MainGame::DrawContent(float fElapsedTime)
{
	/*Draw every Layer in the Layers list*/
	for (auto l : this->Layers) {
		l->Draw(fElapsedTime);
	}
}

void MainGame::ChangeState(int state_id)
{
}

void MainGame::OnEnable()
{
	/*Clear the Screen...*/
	pge->Clear(olc::BLANK);
}

void MainGame::OnDisable()
{
}
