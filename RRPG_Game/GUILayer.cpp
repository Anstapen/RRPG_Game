#include "GUILayer.h"
#include "GUILayerPM.h"
#include "ButtonEvent.h"
#include <memory>

GUILayer::GUILayer(int layerid, PackingManager::PackingStyle pack, std::list<std::shared_ptr<GameObject>> objects) :
	Layer(layerid, pack, objects),
	cursor(nullptr)
{
}

void GUILayer::Setup()
{
}

StateType GUILayer::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	StateType return_state = StateType::NO_CHANGE;
	/* TODO: Add given external Events to internal Eventlist*/
	std::shared_ptr<Event> ret_event;
	for (auto o : this->AllObjects) {
		ret_event = o->Update(fElapsedTime, this->InternalEvents);
	}
	/*Check, if the Event returned any external Events that have to be add to the External Event List*/
	if (ret_event != nullptr) {
		eventlist->push_back(ret_event);
	}
	/*Update the cursor position*/
	this->UpdateCursor(fElapsedTime);
	/*Check if there are Events that change the State of the Game*/
	return_state = this->HandleEvents();
	return return_state;
}

void GUILayer::OnDraw(float fElapsedTime)
{
	/*Draw all the Gui Objects (Buttons, TextBoxes, etc..)*/
	for (auto o : this->AllObjects) {
		o->Draw(fElapsedTime);
	}
	/*After that, draw the Cursor*/
	this->DrawCursor(fElapsedTime);
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

StateType GUILayer::HandleEvents()
{
	StateType return_state = StateType::NO_CHANGE;


	return return_state;
}

void GUILayer::AddCursor(std::shared_ptr<Cursor> in_cursor)
{
	this->cursor = in_cursor;
}

void GUILayer::DrawCursor(float fElapsedTime)
{
	/*If this Layer contains a Cursor, draw it.*/
	if (this->cursor != nullptr) {
		this->cursor->Draw(fElapsedTime);
	}
}

void GUILayer::UpdateCursor(float fElapsedTime)
{
	/*Update the Cursor if there is one*/
	if (this->cursor != nullptr) {
		this->cursor->Update(fElapsedTime, this->InternalEvents);
	}
}
