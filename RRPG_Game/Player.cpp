#include "Player.h"

Player::Player(std::string path, unsigned int noa, float in_speed, bool movable, olc::vf2d pos, bool collidable, std::list<HitBox> CombHitBox) :
	AnimatedGameTile(path, noa, in_speed, movable, pos, collidable, CombHitBox),
	velocity(5.0f),
	AbsolutePosition(20.0f, 12.0f)
{
}

void Player::Draw(float fElapsedTime)
{
	/*Compute actual top left postion of the object*/
	olc::vf2d draw_pos = { (this->CenterPosition.x * 24.0f) - 12.0f, (this->CenterPosition.y * 24.0f) - 12.0f };
	this->image.get()->Draw(fElapsedTime, { draw_pos.x, draw_pos.y });
}

std::shared_ptr<Event> Player::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	/*Update the Absolute Position in the Game Map*/
	if (pge->GetKey(olc::Key::W).bHeld) {
		this->AbsolutePosition.y -= this->velocity * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::S).bHeld) {
		this->AbsolutePosition.y += this->velocity * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::A).bHeld) {
		this->AbsolutePosition.x -= this->velocity * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::D).bHeld) {
		this->AbsolutePosition.x += this->velocity * fElapsedTime;
	}
	/*If the Player is not on the Edge */
	return std::shared_ptr<Event>();
}
