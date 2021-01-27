#include "Actor.h"
#include "ActorComponent.h"

Actor::Actor(ActorId in_ID, std::string in_name) :
	ID(in_ID),
	name(in_name)
{
}


/*This function gets called by the Factory after creation*/
bool Actor::Init(void)
{
	/*Do some Init Stuff*/
	return false;
}

void Actor::postInit(void)
{
	/*Do some post Init Stuff*/
}

void Actor::Destroy()
{
	/*Clear the component map*/
	this->components.clear();
}

void Actor::Update(float fElapsedTime)
{
	/*Gets called every frame, so do some update stuff*/
}

void Actor::AddComponent(StrongActorComponentPtr pComponent)
{
	/*Check, if the pointer is valid*/
	if (pComponent == nullptr) {
		return;
	}

	/*Add the Component to the map*/
	this->components.insert({pComponent.get()->GetID(), pComponent});
}

template<class ComponentType>
std::weak_ptr<ComponentType> Actor::GetComponent(ActorComponentId id)
{
	/*search for the component with the id in the components map*/
	ActorComponents::iterator findIt = this->components.find(id);

	/*Check if the Component was found:*/
	if (findIt != this->components.end()) {
		/*Components are stored by base class pointer reference*/
		StrongActorComponentPtr pBase = findIt->second();

		/*I need to cast it to the subclass pointer*/
		std::shared_ptr<ComponentType> pChild(std::tr1::static_pointer_cast<ComponentType>(pBase));

		/*and create a weak pointer*/
		std::weak_ptr<ComponentType> pRet(pChild);

		/*return the weak pointer*/
		return pRet;
	}
	else {
		return std::weak_ptr<ComponentType>();
	}
	return std::weak_ptr<ComponentType>();
}