#include "ActorFactory.h"
#include "WorldPositionComponent.h"
#include "ScreenPositionComponent.h"
#include "MultiTexture.h"

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
    this->ComponentCreators["MultiTexture"] = MultiTexture::CreateMultiTexture;
    return false;
}
