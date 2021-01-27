#include "IPositionComponent.h"
#include "ActorComponentGUID.h"

/*Initialize the component id*/
/*TODO: Use the VS tool to generate GUIDs at compile time*/
const ActorComponentId IPositionComponent::unique_id = (ActorComponentId)ActorComponentGUID::POSITION_COMP;

ActorComponentId IPositionComponent::GetID(void) const
{
    return IPositionComponent::unique_id;
}
