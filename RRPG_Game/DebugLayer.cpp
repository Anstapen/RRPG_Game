#include "DebugLayer.h"
#include "DebugLayerPM.h"

DebugLayer::DebugLayer(int layerid, std::string pack, std::list<std::shared_ptr<GameObject>> objects) :
	Layer(layerid, pack, objects)
{
}

void DebugLayer::Setup()
{
}

void DebugLayer::Draw(float fElapsedTime)
{
}

StateChanger DebugLayer::Update(float fElapsedTime)
{
	return StateChanger::NO_CHANGE;
}

std::shared_ptr<LayerPM> DebugLayer::GetLayerPM()
{
	return std::shared_ptr<LayerPM>(new DebugLayerPM());
}

bool DebugLayer::OnEnable()
{
	return false;
}

bool DebugLayer::OnDisable()
{
	return false;
}

void DebugLayer::HandleEvents()
{
}
