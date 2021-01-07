#pragma once
#include "LayerPM.h"
class DebugLayerPM :
	public LayerPM
{
public:
	DebugLayerPM(
		std::string in_base_path = std::string(),
		PackingManager::PackingStyle in_pack_type = PackingManager::PackingStyle::DEFAULT
	);
	virtual bool PackLayer(std::shared_ptr<Layer> layer) override;
};

