#include "ActorFactory.h"
#include "WorldPositionComponent.h"
#include "ScreenPositionComponent.h"

StrongActorComponentPtr ActorFactory::CreateComponent(void)
{
    return StrongActorComponentPtr();
}

StrongActorPtr ActorFactory::CreateActor(std::string actor_name)
{

    return StrongActorPtr();
}

bool ActorFactory::Init(void)
{
    /*Populate the ComponentCreators map*/
    this->ComponentCreators["WorldPosition"] = WorldPositionComponent::CreateWorldPosition;
    this->ComponentCreators["ScreenPosition"] = ScreenPositionComponent::CreateScreenPosition;
    return false;
}
