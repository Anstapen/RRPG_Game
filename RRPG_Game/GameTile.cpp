#include "GameTile.h"

GameTile::GameTile(olc::vf2d pos, bool collidable, std::list<HitBox> CombHitBox) :
	GameObject(pos, CombHitBox),
	Collidable(collidable)
{
}

//GameTile::GameTile(const GameTile& other) :
//	GameTile(other.CenterPosition, other.Collidable, other.CombinedHitBox)
//{
//	std::cout << "Copy-Constructed Game Tile!\n";
//}
