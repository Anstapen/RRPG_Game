#pragma once
#include "EventType.h"
class Event
{
public:
	enum class EventPriority {
		VERYLOW = -2,
		LOW = -1,
		NORMAL = 0,
		HIGH = 1,
		VERYHIGH = 2
	};
public:
	EventType GetEventType() const;
protected:
	Event(
		EventType in_type = EventType(EventType::otype::DEFAULT, EventType::etype::DEFAULT),
		EventPriority in_prio = EventPriority::NORMAL
	);
	virtual ~Event();

protected:
	const EventType type;
	EventPriority prio;
};