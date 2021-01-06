#pragma once
class Event
{
public:
	enum class EventType {
		DEFAULT = 1999,
		BUTTON_NEWGAME = 2000,
		BUTTON_EXIT
	};

	enum class EventPriority {
		VERYLOW = -2,
		LOW = -1,
		NORMAL = 0,
		HIGH = 1,
		VERYHIGH = 2
	};

public:
	EventType type = EventType::DEFAULT;
	EventPriority prio = EventPriority::NORMAL;
};

