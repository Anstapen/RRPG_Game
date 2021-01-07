#pragma once
#include "LayerPM.h"
#include <memory>
class GUILayerPM :
	public LayerPM
{
public:
	GUILayerPM(
		std::string in_base_path = std::string(),
		PackingManager::PackingStyle in_pack_type = PackingManager::PackingStyle::DEFAULT
	);
	virtual bool PackLayer(std::shared_ptr<Layer> layer) override;
};

