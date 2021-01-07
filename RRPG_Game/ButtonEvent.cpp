#include "ButtonEvent.h"
#include "ButtonType.h"

ButtonEvent::ButtonEvent(EventType::etype in_subtype) : 
	Event(EventType(EventType::otype::BUTTON,in_subtype), Event::EventPriority::NORMAL),
	testdata(42)
{
}

ButtonEvent::ButtonEvent() :
	Event(EventType(EventType::otype::BUTTON, EventType::etype::DEFAULT), Event::EventPriority::NORMAL),
	testdata(42)
{
}