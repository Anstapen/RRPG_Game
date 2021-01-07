#pragma once
#include "Layer.h"
class DebugLayer :
	public Layer
{
public:
	DebugLayer(
		int layerid,
		PackingManager::PackingStyle pack = PackingManager::PackingStyle::DEFAULT,
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() override;
	virtual void Draw(float fElapsedTime) override;
	virtual StateChanger Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
	virtual std::shared_ptr<LayerPM> GetLayerPM() override;
protected:
	virtual bool OnEnable() override;
	virtual bool OnDisable() override;
	virtual StateChanger HandleEvents() override;
};