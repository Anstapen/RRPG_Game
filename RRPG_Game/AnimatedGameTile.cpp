#define OLC_PGEX_ANIMSPR
#include "AnimatedGameTile.h"
#include "olcPixelGameEngine.h"


AnimatedGameTile::AnimatedGameTile(std::string path, unsigned int noa, bool movable, olc::vf2d pos, bool collidable, std::list<HitBox> CombHitBox) :
	GameTile(pos, collidable, CombHitBox),
	image(std::make_unique<olc::AnimatedSprite>()),
	src(std::make_unique<olc::Renderable>()),
	Movable(movable),
	NumberofAnimations(noa)
{
	/*Set up the Animated Sprite*/
	this->src.get()->Load(path);
	/*this Object only ever uses one single spritesheet*/
	this->image.get()->mode = olc::AnimatedSprite::SPRITE_MODE::SINGLE;
	this->image.get()->spriteSheet = this->src.get();
	this->image.get()->SetSpriteSize({ 24,24 });
	this->image.get()->type = olc::AnimatedSprite::SPRITE_TYPE::DECAL;
	
	/*define default state*/

	/*Create a vector of positions of the frames in the spritesheet*/
	std::vector<olc::vi2d> vec_positions;
	for (unsigned int i = 0; i < this->NumberofAnimations; i++) {
		vec_positions.push_back({ 24 * (int)i, 0 });
	}
	this->image.get()->AddState("default", vec_positions);
	this->image.get()->SetState("default");


}

void AnimatedGameTile::Draw(float fElapsedTime)
{
	/*Compute actual top left postion of the object*/
	olc::vf2d draw_pos = { (this->CenterPosition.x * 24.0f) - 12.0f, (this->CenterPosition.y * 24.0f) - 12.0f };
	this->image.get()->Draw(fElapsedTime, { draw_pos.x, draw_pos.y });
}
