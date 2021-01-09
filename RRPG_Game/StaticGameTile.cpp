#include "StaticGameTile.h"



StaticGameTile::StaticGameTile(std::string in_path, olc::vf2d pos, bool collidable, std::list<HitBox> CombHitBox) :
	GameTile(pos, collidable, CombHitBox),
	image(std::make_unique<olc::Renderable>()),
	path(in_path)
{
	this->image.get()->Load(path);
}

StaticGameTile::StaticGameTile(const StaticGameTile& other) :
	StaticGameTile(other.path, other.CenterPosition, other.Collidable,  other.CombinedHitBox)
{
}

StaticGameTile& StaticGameTile::operator=(const StaticGameTile& other)
{
	/*Check if they are the same*/
	if (this == &other) return *this;
	/*Copy the simple stuff by value*/
	this->path = other.path;
	this->CenterPosition = other.CenterPosition;
	this->Collidable = other.Collidable;
	this->CombinedHitBox = other.CombinedHitBox;
	/*delete previous Renderable Object*/
	this->image.reset();
	/*Create a new Renderable*/
	this->image.get()->Load(path);
	/*return Object*/
	return *this;
}

void StaticGameTile::Draw(float FElapsedTime)
{
	/*Compute actual top left postion of the object*/
	olc::vf2d draw_pos = { (this->CenterPosition.x * 24.0f) - 12.0f, (this->CenterPosition.y * 24.0f) - 12.0f };
	//std::cout << "Drawing at " << draw_pos.x << " x " << draw_pos.y << std::endl;
	pge->DrawDecal(draw_pos, this->image.get()->Decal());
}

std::shared_ptr<Event> StaticGameTile::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	return nullptr;
}
