#include "GameObject.h"
#include "Debug.h"

GameObject::GameObject(olc::vf2d in_pos, std::list<HitBox> CombHitBox) : CenterPosition(in_pos), CombinedHitBox(CombHitBox)
{
/*if the debug is enabled, +1 to the gameobjects count*/
#ifdef DEBUG_GAME
	debug_obj->nGameObjects++;
#endif // DEBUG_GAME

}

GameObject::~GameObject()
{
/*if the debug is enabled, -1 to the gameobjects count*/
#ifdef DEBUG_GAME
	debug_obj->nGameObjects--;
#endif // DEBUG_GAME
}

olc::vf2d GameObject::GetPosition()
{
	return this->CenterPosition;
}

void GameObject::SetPosition(olc::vf2d in_pos)
{
	this->CenterPosition = in_pos;
}
