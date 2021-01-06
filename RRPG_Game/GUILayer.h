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
		std::string pack = "default",
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() override;
	virtual void Update(float FElapsedTime) override;
	virtual void Draw(float fElapsedTime) override;
	virtual std::shared_ptr<LayerPM> GetLayerPM() override;

protected:
	virtual bool OnEnable() override;
	virtual bool OnDisable() override;
};