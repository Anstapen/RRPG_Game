#pragma once
#include "GameObject.h"
#include "olcPixelGameEngine.h"
#include <memory>
#include "LayerPM.h"
#include "Event.h"
#include "State.h"
#include "StateChanger.h"

class LayerPM;
class State;
class Layer : public olc::PGEX
{
public:
	Layer(
		int layerid,
		std::string pack = "default",
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>(),
		std::list<Event> events = std::list<Event>()
	);
	virtual void Setup() = 0;
	virtual void Draw(float fElapsedTime) = 0;
	virtual StateChanger Update(float fElapsedTime);
	virtual std::shared_ptr<LayerPM> GetLayerPM() = 0;
	void AddObject(std::shared_ptr<GameObject> obj);
	bool EnableLayer();
	bool DisableLayer();
protected:
	virtual bool OnEnable() = 0;
	virtual bool OnDisable() = 0;
	virtual void HandleEvents() = 0;
	bool Enabled;
	int ID;
	std::string Packing = "default";
	std::list<std::shared_ptr<GameObject>> AllObjects;
	std::list<Event> IncomingEvents;
};