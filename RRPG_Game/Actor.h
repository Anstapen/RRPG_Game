#pragma once
#include <memory>
#include <map>

#include "ActorFactory.h"
#include "ActorComponent.h"
#include "ActorTypes.h"



class Actor
{
public:
	/*Consturctor and Destructor*/
	explicit Actor(ActorId in_ID, std::string in_name);
	virtual ~Actor(void) = default;
	/*Init function, has to be reviewed*/
	bool Init(void);
	void postInit(void);
	void Destroy();
	void Update(float fElapsedTime);

	/*inline id accessor*/
	ActorId GetID(void) const { return this->ID; }

	/*inline name accessor*/
	std::string GetName(void) const { return this->name; }

	/*template function for retrieving components*/
	template <class ComponentType>
	std::weak_ptr<ComponentType> GetComponent(ActorComponentId id);

private:
	friend class ActorFactory;
	/*map of the ActorComponents that the Actor holds*/
	typedef std::map<ActorComponentId, StrongActorComponentPtr> ActorComponents;

	/*unique id for the Actor*/
	 const ActorId ID;

	 /*not-unique name for the Actor*/
	 const std::string name;

	/*All the components that the actor has*/
	ActorComponents components;

/*private Functions*/
private:
	void AddComponent(StrongActorComponentPtr pComponent);

};


