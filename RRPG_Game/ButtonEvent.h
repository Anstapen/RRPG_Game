#pragma once
#include "Event.h"
#include <memory>




	enum class Key
	{
		NONE,
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		UP, DOWN, LEFT, RIGHT,
		SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
		BACK, ESCAPE, RETURN, ENTER, PAUSE, SCROLL,
		NP0, NP1, NP2, NP3, NP4, NP5, NP6, NP7, NP8, NP9,
		NP_MUL, NP_DIV, NP_ADD, NP_SUB, NP_DECIMAL, PERIOD,
		EQUALS, COMMA, MINUS,
		OEM_1, OEM_2, OEM_3, OEM_4, OEM_5, OEM_6, OEM_7, OEM_8,
		CAPS_LOCK, ENUM_END
	};

	

	/*
		The ButtonEvent gets fired only by the UserInputHandler (for now) everytime
		a Button changes its state (also counting repeated button presses).

		- Key key: the key that fired this event
		- State state: the state the button changed into
		- uint32_t n_held: the number of intervalls the key is already held down, in number of frames (UserInputHandler keeps track of this)


		###### IMPORTANT INFORMATION ######
		As you can see in this class declaration, the contructor of this class is private. The reason is that
		instances of this class should only be created using the overloaded static CreateEvent function.
	*/
	class ButtonEvent : public BaseEvent
	{
	public:
		enum class State {
			PRESSED,
			RELEASED,
			HELD
		};
	public:
		/* implemented pure virtual function from IEvent */
		static const uint32_t GetGUID();

		/* The only way to get a Button Event instance */
		static std::unique_ptr<ButtonEvent> Create(float fElapsedTime, Key key = Key::NONE, State state = State::PRESSED, uint32_t n_held = 0);
		
		virtual ~ButtonEvent();
		Key GetKey() const;
		State GetState()const;

		
	private:
		ButtonEvent(float fElapsedTime, Key key, State state, uint32_t n_held);

	private:
		const Key key;
		const State state;
		uint32_t n_held;
		const static uint32_t guid;
	};
