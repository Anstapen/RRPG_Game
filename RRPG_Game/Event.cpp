#include "Event.h"

EventType Event::GetEventType() const
{
	return this->type;
}

Event::Event(EventType in_type, EventPriority in_prio) :
	type(in_type),
	prio(in_prio)
{
}

Event::~Event()
{
}
