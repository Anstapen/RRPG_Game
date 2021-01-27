#pragma once
#include <memory>

#include "Actor.h"
#include "ActorFactory.h"
#include "ActorTypes.h"


class ActorComponent
{
private:
	friend class ActorFactory;
protected:
	/*Every ActorComponent know its parent Actor*/
	StrongActorPtr owner;
public:
	virtual ~ActorComponent() = default;

	virtual bool Init(void) = 0;
	virtual void PostInit(void);
	virtual void Update(float fElapsedTime);
	/*Get the ActorComponentId that has to be implemented by child classes*/
	virtual ActorComponentId GetID(void) const = 0;
	/**/


/*private Function that only gets invoked by the Factory*/
private:
	void SetOwner(StrongActorPtr in_owner) { this->owner = in_owner; } 
};