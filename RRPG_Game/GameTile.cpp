#include "GameTile.h"

GameTile::GameTile(olc::vf2d pos, bool collidable, std::list<HitBox> CombHitBox) :
	GameObject(pos, CombHitBox),
	Collidable(collidable)
{
}
