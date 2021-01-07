#pragma once
#include "GameTile.h"

#include "olcPGEX_AnimatedSprite.h"
class AnimatedGameTile :
	public GameTile
{
public:
	AnimatedGameTile(
		std::string path,
		unsigned int noa,
		bool movable = false,
		olc::vf2d pos = { 0.0f, 0.0f },
		bool collidable = true,
		std::list<HitBox> CombHitBox = std::list<HitBox>()
	);
	virtual void Draw(float fElapsedTime) override;
	virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
protected:
	std::unique_ptr<olc::AnimatedSprite> image;
	std::unique_ptr<olc::Renderable> src;
	bool Movable;
	unsigned int NumberofAnimations;
};