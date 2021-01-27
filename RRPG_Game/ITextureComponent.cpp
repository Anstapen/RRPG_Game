#include "ITextureComponent.h"
#include "ActorComponentGUID.h"

/*Init the unique id*/
const ActorComponentId ITextureComponent::unique_id = (ActorComponentId)ActorComponentGUID::TEXTURE_COMP;

ActorComponentId ITextureComponent::GetID(void) const
{
    return ITextureComponent::unique_id;
}
