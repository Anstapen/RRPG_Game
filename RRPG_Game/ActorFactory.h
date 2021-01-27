#pragma once
#include <map>
#include <string>

#include "ActorTypes.h"



class ActorFactory
{
private:
	ActorId lastActorId;
	ActorId GetNextActorId(void) { this->lastActorId++; return this->lastActorId; }
protected:
	ActorComponentCreatorMap ComponentCreators;
	virtual StrongActorComponentPtr CreateComponent(void);

public:
	ActorFactory(void) = default;
	StrongActorPtr CreateActor(std::string actor_name);
	bool Init(void);
};