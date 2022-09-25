#pragma once

#include <list>
#include <memory>
#include <map>
#include "Event.h"
/*
	This is the central Event Management System. Basically a Event Storage System that takes
	new (incoming) events and stores them in a specific list.
	It is a templated class (in this case, T represents one of the Event classes).
*/

class EventSystem;


class EventSystem
{
public:
	typedef std::list<std::unique_ptr<BaseEvent>> BaseEventList;
	typedef std::map<uint32_t, std::list<std::unique_ptr<BaseEvent>>> EventMapType;
public:
	/*
		This one is NOT trivial.
	*/
	static int32_t Init();
	static void DeInit();
	static void AddEvent(uint32_t guid, std::unique_ptr<BaseEvent> evt_ptr);
	static const BaseEventList& GetEventList(uint32_t guid);
	static void Update();

private:
	EventSystem();
	virtual ~EventSystem();
	void ClearEventList(uint32_t index);


private:
	/*
		This map holds a list for each Event type. In these lists are all the Events that occured that frame.
		There are two of them, that stores the events for the next frame, and one that currently holds the events of the current frame.
	*/
	std::map<uint32_t, BaseEventList> event_map[2];

	uint32_t current = 0;
	uint32_t next = 1;
};


