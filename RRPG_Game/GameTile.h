#pragma once
#include "GameObject.h"
/*A Game Tile is a Game Object with a fixed size of 24x24 pixel*/
class GameTile :
	public GameObject
{
public:
	GameTile(
		olc::vf2d pos = { 0.0f, 0.0f },
		bool collidable = true,
		std::list<HitBox> CombHitBox = std::list<HitBox>()
	);
	/* This Method draws the Object on the Screen and has to be implemented by the child class*/
	virtual void Draw(float fElapsedTime) = 0;
protected:
	/*Determines if other Objects are obsttructed in their movement if they collide with this object*/
	bool Collidable;
};