#include "EventType.h"


EventType::EventType(EventType::otype in_type, EventType::etype in_subtype) :
	combType(in_type, in_subtype)
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
