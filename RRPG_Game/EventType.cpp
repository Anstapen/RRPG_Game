#include "EventType.h"

unsigned long EventType::static_id = 0;


EventType::EventType(EventType::otype in_type, EventType::etype in_subtype) :
	combType(in_type, in_subtype),
	ID(static_id++)
{
}

std::pair<EventType::otype, EventType::etype> EventType::GetCompleteType() const
{
	return combType;
}

EventType::otype EventType::GetOType() const
{
	return combType.first;
}

EventType::etype EventType::GetEType() const
{
	return combType.second;
}

unsigned long EventType::GetID() const
{
	return this->ID;
}
