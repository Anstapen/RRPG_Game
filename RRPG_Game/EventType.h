#pragma once
#include <utility>

class EventType {
public:
	/*This enum defines the Object that has invoked the event*/
	enum class otype {
		DEFAULT = 0,
		BUTTON = 1
	};
	/*this enum describes what event it actually is*/
	enum class etype {
		DEFAULT = 0,
		CREATE_NEW_GAME,
		SWITCH_TO_DEBUGSCREEN,
		SWITCH_TO_TITLESCREEN,
		SWITCH_TO_CREDITS,
		DEBUG_SLOT1,
		DEBUG_SLOT2,
		DEBUG_SLOT3
	};
public:
	EventType(
		otype in_type = otype::DEFAULT,
		etype in_subtype = etype::DEFAULT
	);
	std::pair<otype, etype> GetCompleteType() const;
	otype GetOType() const;
	etype GetEType() const;
	unsigned long GetID() const;
protected:
	std::pair<otype, etype> combType;
	const unsigned long ID;
private:
	static unsigned long static_id;
};