#include "DebugLayerPM.h"
#include "DebugLayer.h"
#include "SimplePoly.h"
#include "Button.h"

DebugLayerPM::DebugLayerPM(std::string in_base_path, PackingManager::PackingStyle in_pack_type) :
	LayerPM(in_base_path, in_pack_type)
{
}

bool DebugLayerPM::PackLayer(std::shared_ptr<Layer> layer)
{
	/*TODO: Add some text boxes that display some useful information*/
	if(this->sPackingStyle == PackingManager::PackingStyle::DEBUG_SCREEN) {
		
	}
	
	return true;
}