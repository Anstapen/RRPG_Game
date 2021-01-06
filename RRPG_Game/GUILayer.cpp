#include "GUILayer.h"
#include "GUILayerPM.h"

GUILayer::GUILayer(int layerid, std::string pack, std::list<std::shared_ptr<GameObject>> objects) : 
	Layer(layerid, pack, objects)
{
}

void GUILayer::Setup()
{
}

StateChanger GUILayer::Update(float FElapsedTime)
{
	for (auto o : this->AllObjects) {
		o->Update(FElapsedTime);
	}
	return StateChanger::NO_CHANGE;
}

void GUILayer::Draw(float fElapsedTime)
{
	for (auto o : this->AllObjects) {
		o->Draw(fElapsedTime);
	}
}

std::shared_ptr<LayerPM> GUILayer::GetLayerPM()
{
	return std::shared_ptr<LayerPM>(new GUILayerPM());
}

bool GUILayer::OnEnable()
{
	return false;
}

bool GUILayer::OnDisable()
{
	return false;
}

void GUILayer::HandleEvents()
{
}
