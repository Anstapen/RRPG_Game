#define OLC_PGEX_ANIMSPR
#include "AnimatedGameTile.h"
#include "olcPixelGameEngine.h"


AnimatedGameTile::AnimatedGameTile(std::string in_path, unsigned int noa, float in_speed, bool movable, olc::vf2d pos, bool collidable, std::list<HitBox> CombHitBox) :
	GameTile(pos, collidable, CombHitBox),
	image(std::make_unique<olc::AnimatedSprite>()),
	src(std::make_unique<olc::Renderable>()),
	Movable(movable),
	NumberofAnimations(noa),
	speed(in_speed),
	path(in_path)
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
	this->image.get()->AddState("default", this->speed, olc::AnimatedSprite::PLAY_MODE::LOOP, vec_positions);
	this->image.get()->SetState("default");
}

AnimatedGameTile::AnimatedGameTile(const AnimatedGameTile& other) :
	AnimatedGameTile(other.path, other.NumberofAnimations, other.speed, other.Movable, other.CenterPosition, other.Collidable, other.CombinedHitBox)
{
}

AnimatedGameTile& AnimatedGameTile::operator=(const AnimatedGameTile& other)
{
	/*Check if they are the same*/
	if (this == &other) return *this;
	/*Copy the simple stuff by value*/
	this->path = other.path;
	this->CenterPosition = other.CenterPosition;
	this->Collidable = other.Collidable;
	this->CombinedHitBox = other.CombinedHitBox;
	this->speed = other.speed;
	/*delete previous Renderable/Animated Object*/
	this->src.reset();
	this->image.reset();
	/*Create a new Renderable*/
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
	this->image.get()->AddState("default", this->speed, olc::AnimatedSprite::PLAY_MODE::LOOP, vec_positions);
	this->image.get()->SetState("default");

	/*return Object*/
	return *this;
}

void AnimatedGameTile::Draw(float fElapsedTime)
{
	/*Compute actual top left postion of the object*/
	olc::vf2d draw_pos = { (this->CenterPosition.x * 24.0f) - 12.0f, (this->CenterPosition.y * 24.0f) - 12.0f };
	/*If this exact Tile was already drawn on the Screen, draw it again with 0 elapsed time*/
	if (AlreadyDrawn) {
		this->image.get()->Draw(0.0f, { draw_pos.x, draw_pos.y });
	}
	else {
		this->image.get()->Draw(fElapsedTime, { draw_pos.x, draw_pos.y });
		this->AlreadyDrawn = true;
	}
	//this->image.get()->Draw(fElapsedTime, { draw_pos.x, draw_pos.y });
	
	
}

std::shared_ptr<Event> AnimatedGameTile::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	/*Reset the boolean*/
	this->AlreadyDrawn = false;
	return nullptr;
}
