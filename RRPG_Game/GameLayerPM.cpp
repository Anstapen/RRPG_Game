#include "GameLayerPM.h"
#include "AnimatedGameTile.h"
#include "GameLayer.h"

GameLayerPM::GameLayerPM(std::string in_base_path, PackingManager::PackingStyle in_pack_type) :
	LayerPM(in_base_path, in_pack_type)
{
}

bool GameLayerPM::PackLayer(std::shared_ptr<Layer> layer)
{
	/*Cast the Object into an GUILayer Object.
	TODO: IF POSSIBLE; PLEASE AVOID CONDITIONAL DYNAMIC CAST!!!!!!*/
	std::shared_ptr<GameLayer> casted_layer = std::dynamic_pointer_cast<GameLayer>(layer);

	/* Pack the GUI Layer for the MainGame*/
	if (this->sPackingStyle == PackingManager::PackingStyle::MAIN_GAME) {
	

		/*Add the Player (Static tile for now)*/
		std::unique_ptr<AnimatedGameTile> player_tile = std::make_unique<AnimatedGameTile>("./gfx/Blue_Char_Moving.png", 2, 0.5f, false, olc::vf2d(20.0f, 12.0f));
		casted_layer->Player = std::move(player_tile);
	}
	return true;
}
