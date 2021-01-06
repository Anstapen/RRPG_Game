#pragma once
#include "Layer.h"
class DebugLayer :
	public Layer
{
public:
	DebugLayer(
		int layerid,
		std::string pack = "default",
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() override;
	virtual void Draw(float fElapsedTime) override;
	virtual void Update(float fElapsedTime) override;
	virtual std::shared_ptr<LayerPM> GetLayerPM() override;
protected:
	virtual bool OnEnable() override;
	virtual bool OnDisable() override;
};