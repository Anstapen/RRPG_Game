#pragma once
#include "Event.h"
#include "ButtonType.h"
class ButtonEvent :
	public Event
{
public:
	ButtonEvent(
		EventType::etype in_subtype
	);
	ButtonEvent();
protected:
	/* Temporary member to test dynamic cast*/
	int testdata;
};