#pragma once
#include "AnimatedGameTile.h"

namespace game {


	class Player :
		public AnimatedGameTile
	{
	public:
		Player(
			std::string path = "./gfx/Blue_Char_Moving.png",
			unsigned int noa = 2,
			float in_speed = 0.1f,
			std::list<HitBox> CombHitBox = std::list<HitBox>()
		);
		virtual void Draw(float fElapsedTime) override;
		virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
		olc::vf2d GetWSPos() const;

	private:
		float velocity;
		/*Position in World Space*/
		olc::vf2d PositionWS;
	};
}
