#pragma once
#include <memory>
#include <map>
#include <string>

/*Forward Declarations*/
class Actor;
class ActorComponent;
class ActorFactory;

/*An id unique for the actor type*/
typedef unsigned long ActorId;

/*Strong actor pointer*/
typedef std::shared_ptr<Actor> StrongActorPtr;

/*this is the function Signature for the ActorComponentCreator function*/
typedef ActorComponent* (*ActorComponentCreator)(void);

/*this structure maps the names of the ActorComponents to the Creator functions*/
typedef std::map<std::string, ActorComponentCreator> ActorComponentCreatorMap;

/*Strong ActorComponent Pointer*/
typedef std::shared_ptr<ActorComponent> StrongActorComponentPtr;

/*unique ActorComponentId*/
typedef unsigned long ActorComponentId;