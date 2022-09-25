#pragma once
#include "EventType.h"

#define GET_GUID(classname) classname::GetGUID()


/*
	Some general ideas about the event system:

	1. It should NOT be blocking, i. e. it should not invoke any functions.
	2. parts of the application that are interrested in any events, are responsible
	   for checking them.
	3. Events are only active one frame after they have been issued. Any information 
	   that is contained in the events has to be saved.
	4. The Event "Dispatcher" is basically just a giant list structure that holds all
	   the differnt events that have occured that frame.

*/

/*
	Todo List to successfully implement a new Event class:

	1. inherit from BaseEvent and provide GetGUID() with a unique GUID.
	2. if possible, private Constructor and Factory function that returns a unique_ptr
*/

class Event;
class IEnventData;
class BaseEventData;



/*
	This Interface has to be implemented by all the Event classes.
*/
class IEnvent {
public:
	virtual float GetElapsedTime() const = 0;
};

/*
	This is the base EventData class that implements the IEventDataInterface.
*/
class BaseEvent : public IEnvent 
{
public:
	virtual ~BaseEvent();
	
protected:
	BaseEvent(const float fTime);

	float GetElapsedTime() const override;
private:
	const float fElapsedTime;
};