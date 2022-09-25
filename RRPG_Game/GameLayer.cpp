#include "GameLayer.h"
#include "GameLayerPM.h"
#include "Map.h"

GameLayer::GameLayer(int layerid, std::list<std::shared_ptr<GameObject>> objects) :
	Layer(layerid, PackingManager::PackingStyle::MAIN_GAME, objects),
	maps(),
	currentMap(std::make_unique<Map>())
{
}

void GameLayer::Setup()
{
	/*Build Map from CSV*/
	this->currentMap.get()->LoadMap(MAP_ID::DEFAULT);
}

StateType GameLayer::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	StateType return_state = StateType::NO_CHANGE;

	/*Update Player Position*/
	this->Player->Update(fElapsedTime, eventlist);

	/* TODO: Add given external Events to internal Eventlist*/
	std::shared_ptr<Event> ret_event;
	for (auto o : this->AllObjects) {
		ret_event = o->Update(fElapsedTime, this->InternalEvents);
	}

	/*Update Map*/
	this->currentMap->Update(fElapsedTime, this->Player->GetWSPos());

	/*Check, if the Event returned any external Events that have to be add to the External Event List*/
	if (ret_event != nullptr) {
		eventlist->push_back(ret_event);
	}

	/*Check if there are Events that change the State of the Game*/
	return_state = this->HandleEvents();
	return return_state;
}

std::shared_ptr<LayerPM> GameLayer::GetLayerPM()
{
	return std::shared_ptr<GameLayerPM>(new GameLayerPM());
}

bool GameLayer::OnEnable()
{
	return true;
}

bool GameLayer::OnDisable()
{
	return true;
}

void GameLayer::OnDraw(float fElapsedTime)
{
	/*Draw the Map*/
	this->currentMap->Draw(fElapsedTime);
	/*Draw the Player*/
	this->Player.get()->Draw(fElapsedTime);

	/*Draw all the other Objects*/
	for (auto o : this->AllObjects) {
		o->Draw(fElapsedTime);
	}
}

StateType GameLayer::HandleEvents()
{
	return StateType::NO_CHANGE;
}
