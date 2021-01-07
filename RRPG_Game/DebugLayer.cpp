#include "DebugLayer.h"
#include "DebugLayerPM.h"

DebugLayer::DebugLayer(int layerid, PackingManager::PackingStyle pack, std::list<std::shared_ptr<GameObject>> objects) :
	Layer(layerid, pack, objects)
{
}

void DebugLayer::Setup()
{
}

void DebugLayer::Draw(float fElapsedTime)
{
}

StateChanger DebugLayer::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	return StateChanger::NO_CHANGE;
}

std::shared_ptr<LayerPM> DebugLayer::GetLayerPM()
{
	return std::shared_ptr<LayerPM>(new DebugLayerPM(std::string(), this->Packing));
}

bool DebugLayer::OnEnable()
{
	return false;
}

bool DebugLayer::OnDisable()
{
	return false;
}

StateChanger DebugLayer::HandleEvents()
{
	return StateChanger::NO_CHANGE;
}
