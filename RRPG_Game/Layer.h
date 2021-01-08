#pragma once
#include "GameObject.h"
#include "olcPixelGameEngine.h"
#include <memory>
#include "LayerPM.h"
#include "Event.h"
#include "State.h"
#include "StateChanger.h"
#include "PackingManager.h"

class LayerPM;
class State;
class Layer : public olc::PGEX
{
public:
	Layer(
		int layerid,
		PackingManager::PackingStyle pack = PackingManager::PackingStyle::DEFAULT,
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() = 0;
	void Draw(float fElapsedTime);
	virtual StateChanger Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) = 0;
	virtual std::shared_ptr<LayerPM> GetLayerPM() = 0;
	void AddObject(std::shared_ptr<GameObject> obj);
	bool EnableLayer();
	bool DisableLayer();
protected:
	virtual bool OnEnable() = 0;
	virtual bool OnDisable() = 0;
	virtual void OnDraw(float fElapsedTime) = 0;
	virtual StateChanger HandleEvents() = 0;
	bool Enabled;
	const int ID;
	PackingManager::PackingStyle Packing = PackingManager::PackingStyle::DEFAULT;
	std::list<std::shared_ptr<GameObject>> AllObjects;
	std::shared_ptr<std::list<std::shared_ptr<Event>>> InternalEvents;
};