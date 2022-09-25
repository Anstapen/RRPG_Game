#pragma once
#include <chrono>

/*
	A small little class to test the Event System
*/
class ButtonListener
{
public:
	static void Listen(float fElapsedTime);
	static void Start();
	static void End();

private:
	static std::chrono::time_point<std::chrono::system_clock> start;
	static std::chrono::time_point<std::chrono::system_clock> end;
};

