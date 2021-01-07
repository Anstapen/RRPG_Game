#pragma once
#include "GameTile.h"
#include "olcPixelGameEngine.h"

/* A Static Game Object only has one Image that can be displayed.*/
class StaticGameTile :
	public GameTile
{
public:
	StaticGameTile(
		std::string path,
		olc::vf2d pos = { 0.0f, 0.0f },
		bool collidable = true,
		std::list<HitBox> CombHitBox = std::list<HitBox>()
	);
	virtual void Draw(float fElapsedTime) override;
	virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;

protected:
	std::unique_ptr<olc::Renderable> image;
};

