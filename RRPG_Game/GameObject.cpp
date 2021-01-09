#include "GameObject.h"

GameObject::GameObject(olc::vf2d in_pos, std::list<HitBox> CombHitBox) : CenterPosition(in_pos), CombinedHitBox(CombHitBox)
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
