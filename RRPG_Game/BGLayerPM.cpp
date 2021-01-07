#include "BGLayerPM.h"
#include "BGLayer.h"

BGLayerPM::BGLayerPM(std::string in_base_path, PackingManager::PackingStyle in_pack_type) :
	LayerPM(in_base_path, in_pack_type)
{
}

bool BGLayerPM::PackLayer(std::shared_ptr<Layer> layer)
{

	/*For now, nothing has to be done for the BG Layer*/
	return true;
}
