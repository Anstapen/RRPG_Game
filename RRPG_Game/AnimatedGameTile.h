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
		float in_speed = 0.5f,
		bool movable = false,
		olc::vf2d pos = { 0.0f, 0.0f },
		bool collidable = true,
		std::list<HitBox> CombHitBox = std::list<HitBox>()
	);
	/*Rule of Three*/
	virtual ~AnimatedGameTile() = default;
	AnimatedGameTile(const AnimatedGameTile& other);
	AnimatedGameTile& operator=(const AnimatedGameTile& other);

	virtual void Draw(float fElapsedTime) override;
	virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
protected:
	std::unique_ptr<olc::AnimatedSprite> image;
	std::unique_ptr<olc::Renderable> src;
	std::string path;
	bool Movable;
	float speed;
	unsigned int NumberofAnimations;
	/*Value to check if we have already drawn this Tile this Frame, gets reset at Update*/
	bool AlreadyDrawn = false;
};