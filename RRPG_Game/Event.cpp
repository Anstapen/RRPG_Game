#include "Event.h"

BaseEvent::BaseEvent(const float fTime) : fElapsedTime(fTime)
{
}

BaseEvent::~BaseEvent()
{
}

float BaseEvent::GetElapsedTime() const
{
	return this->fElapsedTime;
}
