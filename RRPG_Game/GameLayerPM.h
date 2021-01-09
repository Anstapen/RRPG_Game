#pragma once
#include "LayerPM.h"
class GameLayerPM :
	public LayerPM
{
public:
	GameLayerPM(
		std::string in_base_path = std::string(),
		PackingManager::PackingStyle in_pack_type = PackingManager::PackingStyle::MAIN_GAME
	);
	virtual bool PackLayer(std::shared_ptr<Layer> layer) override;
};

