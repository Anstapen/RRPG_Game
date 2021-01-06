#pragma once
#include "PackingManager.h"
#include <memory>
#include "Layer.h"
class Layer;

class LayerPM :
	public PackingManager
{
public:
	virtual bool PackLayer(std::shared_ptr<Layer> layer) = 0;
};