#pragma once
#include "Event.h"
#include <list>
#include <memory>
class EventBroker
{
protected:
	/*This is the list of all Events*/
	std::list<std::shared_ptr<Event>> eventlist;
};