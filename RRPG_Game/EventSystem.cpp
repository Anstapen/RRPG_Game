#include "EventSystem.h"
#include <assert.h>


/* The static EventSystem object */
static EventSystem* es = NULL;


EventSystem::~EventSystem()
{

}

EventSystem::EventSystem()
{
}

void EventSystem::ClearEventList(uint32_t index)
{
	assert(this);
	/* Iterate through the map */
	for (EventMapType::iterator it = this->event_map[index].begin(); it != this->event_map[index].end();)
	{
		/* Extract the actual list from the current pair */
		BaseEventList &current_list = (*it).second;

		/* Run through the list and delete every unique_ptr */
		for (BaseEventList::iterator it2 = current_list.begin(); it2 != current_list.end();)
		{
			(*it2).reset();
			it2 = current_list.erase(it2);
		}

		/* List is empty now delete it from the map */
		it = this->event_map[index].erase(it);
	}
}



int32_t EventSystem::Init()
{
	es = new EventSystem();
	return 0;
}

void EventSystem::DeInit()
{
	delete es;
	es = NULL;
}

/*
	
*/
void EventSystem::AddEvent(uint32_t guid, std::unique_ptr<BaseEvent> evt_ptr)
{
	assert(es);
	/* Find the list with the equivalent guid */
	/* dont use contains, would only be faster if the list is not yet created, which is only the case in the beginning */
	auto index = es->event_map[es->next].find(guid);
	if (index == es->event_map[es->next].end())
	{
		/* The eventlist for this specific Event does not exist yet, create it */
		es->event_map[es->next].insert(std::pair<uint32_t, BaseEventList>(guid, BaseEventList()));
		
	}
	/* Insert the unqiue_ptr of the event */
	es->event_map[es->next].at(guid).push_back(std::move(evt_ptr));
}

const EventSystem::BaseEventList& EventSystem::GetEventList(uint32_t guid)
{
	assert(es);
	auto index = es->event_map[es->current].find(guid);
	if (index == es->event_map[es->current].end())
	{
		/* The eventlist for this specific Event does not exist yet, create it */
		es->event_map[es->current].insert(std::pair<uint32_t, BaseEventList>(guid, BaseEventList()));
	}
	return es->event_map[es->current].at(guid);
}



/*
	This function gets called by the Game each time OnUserUpdate gets executed.
*/
void EventSystem::Update()
{
	assert(es);
	/* Clear the current event list */
	es->ClearEventList(es->current);

	/* swap the event list indices */
	uint32_t index_next = es->current;
	es->current = es->next;
	es->next = index_next;
}



