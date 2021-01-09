#include "DebugLayer.h"
#include "DebugLayerPM.h"

DebugLayer::DebugLayer(int layerid, PackingManager::PackingStyle pack, std::list<std::shared_ptr<GameObject>> objects) :
	Layer(layerid, pack, objects)
{
}

void DebugLayer::Setup()
{
}

void DebugLayer::OnDraw(float fElapsedTime)
{
	for (auto o : this->AllObjects) {
		o->Draw(fElapsedTime);
	}
}

StateChanger DebugLayer::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{

	/*Update all Objects, including our Polygons*/
	for (auto o : this->AllObjects) {
		o->Update(fElapsedTime, eventlist);
	}
	return StateChanger::NO_CHANGE;
}

std::shared_ptr<LayerPM> DebugLayer::GetLayerPM()
{
	return std::shared_ptr<LayerPM>(new DebugLayerPM(std::string(), this->Packing));
}

bool DebugLayer::OnEnable()
{
	return true;
}

bool DebugLayer::OnDisable()
{
	return true;
}

StateChanger DebugLayer::HandleEvents()
{
	return StateChanger::NO_CHANGE;
}
