#include "ButtonListener.h"
#include "ButtonEvent.h"
#include "EventSystem.h"
#include <iostream>

std::chrono::time_point<std::chrono::system_clock> ButtonListener::start;
std::chrono::time_point<std::chrono::system_clock> ButtonListener::end;

void ButtonListener::Listen(float fElapsedTime)
{
	/*
		Check the Button Events...
	*/
	uint32_t events_processed = 0;
	/* At the moment, we need a Button Event to get the guid */
	uint32_t button_guid = GET_GUID(ButtonEvent);
	const EventSystem::BaseEventList& event_list = EventSystem::GetEventList(button_guid);
	for (auto it = event_list.begin(); it != event_list.end(); ++it)
	{
		/* cast it to a ButtonEvent */
		volatile uint32_t test_button_guid = dynamic_cast<ButtonEvent*>((*it).get())->GetGUID();
		ButtonEvent::State test_state = dynamic_cast<ButtonEvent*>((*it).get())->GetState();
		events_processed++;
	}
	if (events_processed > 0)
	{
		/*ButtonListener::End();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::cout << "Button events processed: " << events_processed << std::endl;
		std::cout << "It took: " << elapsed_seconds.count() << " Seconds" << std::endl;*/
	}
}

void ButtonListener::Start()
{
	ButtonListener::start = std::chrono::system_clock::now();
}

void ButtonListener::End()
{
	ButtonListener::end = std::chrono::system_clock::now();
}
