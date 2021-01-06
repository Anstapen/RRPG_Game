#pragma once
#include "GameObject.h"
#include "olcPixelGameEngine.h"
#include <memory>
#include "LayerPM.h"

class LayerPM;
class Layer : public olc::PGEX
{
public:
	Layer(
		int layerid,
		std::string pack = "default",
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() = 0;
	virtual void Draw(float fElapsedTime) = 0;
	virtual void Update(float fElapsedTime) = 0;
	virtual std::shared_ptr<LayerPM> GetLayerPM() = 0;
	void AddObject(std::shared_ptr<GameObject> obj);
	bool EnableLayer();
	bool DisableLayer();
protected:
	virtual bool OnEnable() = 0;
	virtual bool OnDisable() = 0;
	bool Enabled;
	int ID;
	std::string Packing = "default";
	std::list<std::shared_ptr<GameObject>> AllObjects;
};