#pragma once
#include "olcPixelGameEngine.h"
#include "GameObject.h"


	class CEllipse : public GameObject
	{
	public:
		void Draw(float fElapsedTime) override;
		virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
	public:
		/*postion on the screen*/
		CEllipse(
			olc::vf2d pos,
			unsigned int a = 12,
			unsigned int b = 5
		);

	private:
		unsigned int GetYFromX(float x);
		olc::vi2d GetAbsolutePos(int x, int y);
		/* magnitude of a (y value is always 0)*/
		unsigned int a;
		/* magnitude of b (x value is always 0)*/
		unsigned int b;

		/*Both values squared (so we do not need to compute them everytime*/
		unsigned int a_s;
		unsigned int b_s;
	};
