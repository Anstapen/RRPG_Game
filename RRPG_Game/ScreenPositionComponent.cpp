#include "ScreenPositionComponent.h"

ScreenPositionComponent::ScreenPositionComponent()
{
}

ActorComponent* ScreenPositionComponent::CreateScreenPosition()
{
	return new ScreenPositionComponent;
}

bool ScreenPositionComponent::Init(void)
{
	/*Dont do anything for now*/
	return true;
}

olc::vf2d ScreenPositionComponent::GetPosition(void)
{
	return this->pos;
}

void ScreenPositionComponent::SetPosition(olc::vf2d new_pos)
{
	this->pos = new_pos;
}
