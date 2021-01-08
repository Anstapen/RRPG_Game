#pragma once
#include "Layer.h"
#include "LayerPM.h"
class GUILayer :
	public Layer
{
	friend class GUILayerPM;
public:
	GUILayer(
		int layerid,
		PackingManager::PackingStyle pack = PackingManager::PackingStyle::DEFAULT,
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() override;
	virtual StateChanger Update(float FElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
	
	virtual std::shared_ptr<LayerPM> GetLayerPM() override;

protected:
	virtual bool OnEnable() override;
	virtual bool OnDisable() override;
	virtual void OnDraw(float fElapsedTime) override;
	virtual StateChanger HandleEvents() override;
};