#include "DebugLayerPM.h"
#include "DebugLayer.h"

DebugLayerPM::DebugLayerPM(std::string in_base_path, PackingManager::PackingStyle in_pack_type) :
	LayerPM(in_base_path, in_pack_type)
{
}

bool DebugLayerPM::PackLayer(std::shared_ptr<Layer> layer)
{
	/*TODO: Add some text boxes that display some useful information*/
	switch (this->sPackingStyle) {
	case PackingManager::PackingStyle::DEFAULT:
		break;
	default:
		break;
	}
	
	return true;
}