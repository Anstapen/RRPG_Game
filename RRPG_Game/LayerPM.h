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
protected:
	LayerPM(
		std::string in_base_path = std::string(),
		PackingManager::PackingStyle in_pack_type = PackingManager::PackingStyle::DEFAULT
	);
};