#include "GUILayer.h"
#include "GUILayerPM.h"
#include "ButtonEvent.h"
#include <memory>

GUILayer::GUILayer(int layerid, PackingManager::PackingStyle pack, std::list<std::shared_ptr<GameObject>> objects) :
	Layer(layerid, pack, objects)
{
}

void GUILayer::Setup()
{
}

StateChanger GUILayer::Update(float FElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	StateChanger return_state = StateChanger::NO_CHANGE;
	/* TODO: Add given external Events to internal Eventlist*/
	std::shared_ptr<Event> ret_event;
	for (auto o : this->AllObjects) {
		ret_event = o->Update(FElapsedTime, this->InternalEvents);
	}
	/*Check, if the Event returned any external Events that have to be add to the External Event List*/
	if (ret_event != nullptr) {
		eventlist->push_back(ret_event);
	}
	/*Check if there are Events that change the State of the Game*/
	return_state = this->HandleEvents();
	return return_state;
}

void GUILayer::OnDraw(float fElapsedTime)
{
	for (auto o : this->AllObjects) {
		o->Draw(fElapsedTime);
	}
}

std::shared_ptr<LayerPM> GUILayer::GetLayerPM()
{
	return std::shared_ptr<LayerPM>(new GUILayerPM(std::string(), this->Packing));
}

bool GUILayer::OnEnable()
{
	return true;
}

bool GUILayer::OnDisable()
{
	return true;
}

StateChanger GUILayer::HandleEvents()
{
	StateChanger return_state = StateChanger::NO_CHANGE;
	/*Check if there are any Events that change the State of the Game*/

	std::list<std::shared_ptr<Event>>::iterator i = (*(this->InternalEvents)).begin();

	while (i != (*(this->InternalEvents)).end()) {
		
		/*Check Events based on Event Type*/
		switch ((*i)->GetEventType().GetEType()) {
		case EventType::etype::CREATE_NEW_GAME:
			return_state = StateChanger::NEW_GAME;
			/*Event has been processed, remove it from the List*/
			i = this->InternalEvents->erase(i);
			break;
		case EventType::etype::SWITCH_TO_DEBUGSCREEN:
			return_state = StateChanger::DEBUG;
			i = this->InternalEvents->erase(i);
			break;
		default:
			i++;
			break;
		}
	}

	return return_state;
}