#include "Overlay.h"

Overlay::Overlay(std::string path, olc::vf2d pos, float in_width, float in_height):
	GameObject(pos),
	image(std::make_unique<olc::Renderable>()),
	width(in_width),
	height(in_height),
	drawing_pos({0.0f, 0.0f})
{
	/*Calculate the drawing pos*/
	drawing_pos = { this->CenterPosition.x - (width / 2), this->CenterPosition.y - (height / 2) };
	/*Load the image*/
	this->image.get()->Load(path);
}

void Overlay::Draw(float fElapsedTime)
{
	/*Calculate Actual Drawing Position*/
	pge->DrawDecal(this->drawing_pos, this->image.get()->Decal());
}

std::shared_ptr<Event> Overlay::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	/*Change the drawing pos depending on some events*/
	return std::shared_ptr<Event>();
}
