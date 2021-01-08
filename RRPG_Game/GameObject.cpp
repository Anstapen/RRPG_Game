#include "GameObject.h"

GameObject::GameObject(olc::vf2d pos, std::list<HitBox> CombHitBox) : CenterPosition(pos), CombinedHitBox(CombHitBox)
{
}

olc::vf2d GameObject::GetPosition()
{
	return this->CenterPosition;
}

void GameObject::SetPosition(olc::vf2d in_pos)
{
	this->CenterPosition = in_pos;
}
