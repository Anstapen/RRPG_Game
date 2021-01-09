#pragma once
#include "GameObject.h"
class Overlay :
	public GameObject
{
public:
	Overlay(
		std::string path,
		olc::vf2d pos = { 480, 288 },
		float in_width = 960,
		float in_height = 576
	);
	virtual void Draw(float fElapsedTime) override;
	virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
protected:
	std::unique_ptr<olc::Renderable> image;
	float width;
	float height;
	olc::vf2d drawing_pos;
};