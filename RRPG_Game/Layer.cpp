#include "Layer.h"

Layer::Layer(int layerid, PackingManager::PackingStyle pack, std::list<std::shared_ptr<GameObject>> objects) :
	ID(layerid),
	Packing(pack),
	AllObjects(objects),
	InternalEvents(std::make_shared<std::list<std::shared_ptr<Event>>>()),
	Enabled(false)
{
}


void Layer::AddObject(std::shared_ptr<GameObject> obj)
{
	this->AllObjects.push_back(obj);
}

bool Layer::EnableLayer()
{
	bool ret_val = this->OnEnable();
	if (ret_val) {
		this->Enabled = true;
		pge->EnableLayer(this->ID, this->Enabled);
	}
	return ret_val;
}

bool Layer::DisableLayer()
{
	bool ret_val = this->OnDisable();
	if (ret_val) {
		this->Enabled = false;
		pge->EnableLayer(this->ID, this->Enabled);
	}
	return ret_val;
}
