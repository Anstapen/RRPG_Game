#pragma once
#include "LayerPM.h"
class BGLayerPM :
	public LayerPM
{
public:
	virtual bool PackLayer(std::shared_ptr<Layer> layer) override;
};