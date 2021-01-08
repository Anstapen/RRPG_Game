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
	olc::vf2d curr_pos = this->poly1->GetPosition();
	/*Update the polygons depending on the key presses*/
	if(pge->GetKey(olc::Key::W).bHeld) {
		curr_pos.y -= 100.0f * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::S).bHeld) {
		curr_pos.y += 100.0f * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::D).bHeld) {
		curr_pos.x += 100.0f * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::A).bHeld) {
		curr_pos.x -= 100.0f * fElapsedTime;
	}
	this->poly1->SetPosition(curr_pos);

	/*Update all Objects, including our Polygons*/
	for (auto o : this->AllObjects) {
		o->Update(fElapsedTime, eventlist);
	}
	/*Check for Collision*/
	this->poly1->Colliding = this->poly1->CheckOverlapSAT(this->poly2);
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
