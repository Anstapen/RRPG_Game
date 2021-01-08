#pragma once
#include "GameObject.h"
#include <vector>
class SimplePoly :
	public GameObject
{
public:
	SimplePoly(
		olc::vf2d in_pos,
		std::vector<olc::vf2d> in_points
	);
	virtual void Draw(float fElapsedTime) override;
	virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
	bool CheckOverlapSAT(std::shared_ptr<SimplePoly> poly);
	bool Colliding = false;
protected:
	const std::vector<olc::vf2d> rpoints;
	std::vector<olc::vf2d> tpoints;
	float angle;
};