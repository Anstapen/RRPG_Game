#include "ButtonEvent.h"


const uint32_t ButtonEvent::guid(0x582944d2);

std::unique_ptr<ButtonEvent> ButtonEvent::Create(float fElapsedTime, Key key, State state, uint32_t n_held)
{
	/* not pretty, but working...*/
	/* This is the ONLY raw pointer referncing this object, it dies when this function exits*/
	ButtonEvent* ptr = new ButtonEvent(fElapsedTime, key, state, n_held);
	return std::unique_ptr<ButtonEvent>(ptr);
}

ButtonEvent::~ButtonEvent()
{
}

Key ButtonEvent::GetKey() const
{
	return this->key;
}

ButtonEvent::State ButtonEvent::GetState() const
{
	return this->state;
}


const uint32_t ButtonEvent::GetGUID()
{
	return ButtonEvent::guid;
}

ButtonEvent::ButtonEvent(float fElapsedTime, Key key, State state, uint32_t n_held) : BaseEvent(fElapsedTime), key(key), state(state), n_held(n_held)
{
}
