#include "Player.h"

using namespace game;

Player::Player(std::string path, unsigned int noa, float in_speed, std::list<HitBox> CombHitBox) :
	AnimatedGameTile(path, noa, in_speed, true, olc::vf2d((pge->ScreenWidth()/2) / 24, (pge->ScreenHeight()/2)/24), true, CombHitBox),
	velocity(5.0f),
	PositionWS(20.0f, 12.0f)
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
	/*Update the Position in World Space*/
	if (pge->GetKey(olc::Key::W).bHeld) {
		this->PositionWS.y -= this->velocity * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::S).bHeld) {
		this->PositionWS.y += this->velocity * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::A).bHeld) {
		this->PositionWS.x -= this->velocity * fElapsedTime;
	}
	if (pge->GetKey(olc::Key::D).bHeld) {
		this->PositionWS.x += this->velocity * fElapsedTime;
	}
	
	return std::shared_ptr<Event>();
}

olc::vf2d game::Player::GetWSPos() const
{
	return this->PositionWS;
}
