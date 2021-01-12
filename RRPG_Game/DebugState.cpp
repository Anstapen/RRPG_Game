#include "DebugState.h"
#include "GUILayer.h"
#include "BGLayer.h"
#include "DebugLayer.h"
#include "SimplePoly.h"
#include "Button.h"

DebugState::DebugState(StateType in_type) :
	State(in_type)
{
}

StateType DebugState::Execute(float fElapsedTime)
{
	StateType returnState = StateType::NO_CHANGE;

	/*Update all the Layers using the Elapsed Time.
	  In the DebugState, no Layers can invoke a State Change, only the ESC Button*/
	StateType tempState;
	for (auto l : this->Layers) {
		tempState = l->Update(fElapsedTime, this->ExternalEvents);
		if (tempState != StateType::NO_CHANGE) {
			returnState = tempState;
		}
	}

	/*Check for ESC Key Press*/
	if (pge->GetKey(olc::ESCAPE).bReleased) {
		returnState = StateType::TITLESCREEN;
	}
	return returnState;
}


bool DebugState::Setup()
{
	std::cout << "Executing Setup Routine for DebugScreen...\n";
	std::cout << "Adding Objects...\n";

	/*temp int variable to store the layer IDs*/
	int lay_id = 0;

	

	/*Adding the GUI Layer*/
	lay_id = pge->CreateLayer();
	/*Create GUI Layer instance and add it to the Layers list*/
	std::shared_ptr<GUILayer> debug_gui = std::make_shared<GUILayer>(lay_id, PackingManager::PackingStyle::DEBUG_SCREEN);
	this->Layers.push_back(debug_gui);

	/* Adding the Debug Layer*/
	lay_id = pge->CreateLayer();
	std::shared_ptr<DebugLayer> debug_layer = std::make_shared<DebugLayer>(lay_id, PackingManager::PackingStyle::DEBUG_SCREEN);


	/* Adding the Background Layer*/
	lay_id = pge->CreateLayer();
	std::shared_ptr<BGLayer> debug_background = std::make_shared<BGLayer>(lay_id, pge->ScreenWidth(), pge->ScreenHeight(), std::string(), olc::WHITE);
	this->Layers.push_back(debug_background);

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
	/*Clear Layer 0 to Transparent, because this Layer never gets used*/
	pge->Clear(olc::BLANK);

	return true;
}

void DebugState::DrawContent(float fElapsedTime)
{
	/*Draw every Layer in the Layers list*/
	for (auto l : this->Layers) {
		l->Draw(fElapsedTime);
	}
}


void DebugState::OnEnable()
{
	/*Clear the Screen...*/
	pge->Clear(olc::BLANK);
}

void DebugState::OnDisable()
{
}
