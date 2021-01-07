#include "StaticGameTile.h"


StaticGameTile::StaticGameTile(std::string path, olc::vf2d pos, bool collidable, std::list<HitBox> CombHitBox) :
	GameTile(pos, collidable, CombHitBox),
	image(std::make_unique<olc::Renderable>())
{
	this->image.get()->Load(path);
}

void StaticGameTile::Draw(float FElapsedTime)
{
	/*Compute actual top left postion of the object*/
	olc::vf2d draw_pos = { (this->CenterPosition.x * 24.0f) - 12.0f, (this->CenterPosition.y * 24.0f) - 12.0f };
	std::cout << "Drawing at " << draw_pos.x << " x " << draw_pos.y << std::endl;
	pge->DrawDecal(draw_pos, this->image.get()->Decal());
}

std::shared_ptr<Event> StaticGameTile::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	return nullptr;
}
