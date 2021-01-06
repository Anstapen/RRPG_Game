#pragma once
#include "LayerPM.h"
#include <memory>
class GUILayerPM :
	public LayerPM
{
public:
	virtual bool PackLayer(std::shared_ptr<Layer> layer) override;
};

