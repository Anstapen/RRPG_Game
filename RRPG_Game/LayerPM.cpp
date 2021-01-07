#include "LayerPM.h"

bool LayerPM::PackLayer(std::shared_ptr<Layer> layer)
{
	/*This is the Go-To Packing Manager for any new defined Layers, if you dont create your own derived class.
	TODO: Do something useful in here, load some default objects to show that this layer is built by the default PackingManager*/
	return true;
}

LayerPM::LayerPM(std::string in_base_path, PackingManager::PackingStyle in_pack_type) :
	PackingManager(in_base_path, in_pack_type)
{
}
