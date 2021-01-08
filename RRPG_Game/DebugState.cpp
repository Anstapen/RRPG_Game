#include "DebugState.h"
#include "GUILayer.h"
#include "BGLayer.h"
#include "DebugLayer.h"
#include "SimplePoly.h"
#include "Button.h"

DebugState::DebugState(std::string name) :
	State(name)
{
}

StateChanger DebugState::Execute(float fElapsedTime)
{
	StateChanger returnState = StateChanger::NO_CHANGE;

	/*Update all the Layers using the Elapsed Time.
	  In the DebugState, no Layers can invoke a State Change, only the ESC Button*/
	StateChanger tempState;
	for (auto l : this->Layers) {
		tempState = l->Update(fElapsedTime, this->ExternalEvents);
		if (tempState != StateChanger::NO_CHANGE) {
			returnState = tempState;
		}
	}

	/*Check for ESC Key Press*/
	if (pge->GetKey(olc::ESCAPE).bReleased) {
		returnState = StateChanger::TITLESCREEN;
	}
	return returnState;
}

std::string DebugState::GetStateStringFromChanger(StateChanger state)
{
	switch (state) {
	case StateChanger::MAIN_GAME:
		return "MainGame";
		break;
	case StateChanger::TITLESCREEN:
		return "TitleScreen";
		break;
	case StateChanger::NO_CHANGE:
		return "DebugScreen";
		break;
	case StateChanger::DEBUG:
		return "DebugScreen";
		break;
	default:
		return "TitleScreen";
		break;
	}
	return std::string();
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

	std::vector<olc::vf2d> points = { {-7, 4}, {7, 4}, {12, 0}, {7, -4}, {-7, -4}, {-12, 0} };
	/*Add two Polygons*/
	std::shared_ptr<SimplePoly> in_poly1 = std::make_shared<SimplePoly>(olc::vf2d(100.0f, 100.0f), points);
	std::shared_ptr<SimplePoly> in_poly2 = std::make_shared<SimplePoly>(olc::vf2d(150.0f, 150.0f), points);

	debug_layer->AddObject(in_poly1);
	debug_layer->AddObject(in_poly2);
	debug_layer->poly1 = in_poly1;
	debug_layer->poly2 = in_poly2;
	this->Layers.push_back(debug_layer);

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
	/*Draw every object in the AllObjects list*/
	for (auto l : this->Layers) {
		l->Draw(fElapsedTime);
	}
}

void DebugState::ChangeState(int state_id)
{
}

void DebugState::OnEnable()
{
	/*Clear the Screen...*/
	pge->Clear(olc::BLANK);
}

void DebugState::OnDisable()
{
}
