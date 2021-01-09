#pragma once
#include "AnimatedGameTile.h"
class Player :
	public AnimatedGameTile
{
public:
	Player(
		std::string path = "./gfx/Blue_Char_Moving.png",
		unsigned int noa = 2,
		float in_speed = 0.1f,
		bool movable = true,
		olc::vf2d pos = { 0.0f, 0.0f },
		bool collidable = true,
		std::list<HitBox> CombHitBox = std::list<HitBox>()
	);
	virtual void Draw(float fElapsedTime) override;
	virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;

private:
	float velocity;
	olc::vf2d AbsolutePosition;
};

