#include "WorldPositionComponent.h"

ActorComponent* WorldPositionComponent::CreateWorldPosition()
{
    return new WorldPositionComponent;
}

WorldPositionComponent::WorldPositionComponent() :
    pos(olc::vf2d(0.0f, 0.0f))
{
}

bool WorldPositionComponent::Init(void)
{
    /*For now, we do not need to init anything*/
    return true;
}

olc::vf2d WorldPositionComponent::GetPosition(void)
{
    return this->pos;
}

void WorldPositionComponent::SetPosition(olc::vf2d new_pos)
{
    this->pos = new_pos;
}
