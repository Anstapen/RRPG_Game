#include "Texture.h"
#include "AppLayer.h"
#include "olcPixelGameEngine.h"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;


Texture::Texture(std::string in_name) :
	name(in_name),
	image(std::make_unique<olc::AnimatedSprite>()),
	src(std::make_unique<olc::Renderable>()),
	valid(false),
	active(false)
{
	this->valid = this->loadTexture(name);
	if (this->valid) {
		Enable();
	}
}

Texture::Texture(const Texture& other) :
	name(other.name),
	image(std::make_unique<olc::AnimatedSprite>()),
	src(std::make_unique<olc::Renderable>()),
	valid(false)
{
	std::cout << "Copy Constructor!..." << std::endl;
	/*Set up the second texture*/
	this->valid = this->loadTexture(name);
	if (this->valid) {
		Enable();
	}
}


void Texture::SetState(std::string new_state)
{
	this->image.get()->SetState(new_state);
}

/*Draws the texture at the given position, if its active*/
void Texture::Draw(float fElapsedTime, olc::vf2d pos)
{
	if (this->active) {
		this->image.get()->Draw(fElapsedTime, pos);
	}
}


/*TODO: Organize this abomination of an function....*/

bool Texture::loadTexture(std::string name)
{
	bool ret_value = false;
	olc::vi2d size;
	float scale = 0.0f;
	std::vector<texture_state> states;
	/*Load the texture from the json config file*/
	std::string config_path = "./" + AppLayer::GetJsonPath() + "/" + AppLayer::GetTextureFileName();
	std::string texture_path = "./" + AppLayer::GetTexturePath() + "/";

	/*Debug Print*/
	std::cout << "Created this path for the config file: " << config_path << std::endl;
	std::cout << "Created this path for the textures: " << texture_path << std::endl;

	std::ifstream i(config_path);
	json j;
	i >> j;
	/*Check for the textures array*/
	if (j["Textures"].is_null() == true) {
		std::cout << "Did not find the Textures[] array, leaving..." << std::endl;
		return ret_value;
	}
	
	/*Found the textures array, search it for the name...*/
	for (auto& e : j["Textures"]) {
		if (!(e["Warrior"].is_null())) {
			std::cout << "Found our object" << std::endl;
			/*Found our object*/
			auto obj =  e["Warrior"];


			/*Add the path*/
			ret_value = FillPath(obj, texture_path);
			/*Check if that was successfull*/
			if (!ret_value) {
				std::cout << "did not find path of texture for " << name << ", exiting..." << std::endl;
				return ret_value;
			}
			else {
				std::cout << "Found texture path for " << name << ": " << texture_path << std::endl;
			}
			

			/*Add the size*/
			ret_value = FillSize(obj, size);
			if (!ret_value) {
				std::cout << "Failed finding a correct texture size..." << std::endl;
				return ret_value;
			}
			else {
				std::cout << "Found size of " << name << " texture: [" << size.x << ", " << size.y << "]" << std::endl;
			}
			
			/*Add the scale*/
			ret_value = FillScale(obj, scale);
			if (!ret_value) {
				std::cout << "did not find scale of texture for " << name << ", exiting..." << std::endl;
				return ret_value;
			}
			else {
				std::cout << "Found scale for " << name << ": " << scale << std::endl;
			}

			/*Add the States*/
			ret_value = FillStates(obj, states);
			if (!ret_value) {
				std::cout << "did not find texture states for " << name << ", exiting..." << std::endl;
				return ret_value;
			}
			else {
				std::cout << "Found texture states for " << name << ": " << states.size() << std::endl;
			}
		}
	}
	std::cout << "Creating the Animated Sprite..." << texture_path << std::endl;
	/*Filled the variables, creating the object*/
	if (this->src.get() == nullptr)std::cout << "test" << std::endl;
	this->src.get()->Load("./gfx/Blue_Char_Moving.png");
	
	this->image.get()->mode = olc::AnimatedSprite::SPRITE_MODE::SINGLE;
	this->image.get()->spriteSheet = this->src.get();
	this->image.get()->SetSpriteSize(size);
	this->image.get()->type = olc::AnimatedSprite::SPRITE_TYPE::DECAL;
	this->image.get()->SetSpriteScale(scale);
	std::cout << "Animated Sprite created, adding states..." << std::endl;
	/*Set up the States*/
	for (auto &e : states) {
		this->image.get()->AddState(e.name, e.duration, olc::AnimatedSprite::PLAY_MODE::LOOP, e.frames);
	}
	/*For now, set the first state as default*/
	this->image.get()->SetState(states[0].name);
	ret_value = true;

	/*return the rat value*/
	return ret_value;
}

bool Texture::FillPath(const nlohmann::json& obj, std::string &path)
{
	/*Check the path*/
	if (obj["path"].is_null()) {
		return false;
	}
	else {
		path += obj["path"];
		return true;
	}
}

bool Texture::FillSize(const nlohmann::json& obj, olc::vi2d& vec)
{
	if (obj["size"].is_null()) {
		return false;
	}
	else if (obj["size"].size() != 2) {
		return false;
	}
	else {
		vec.x = obj["size"][0];
		vec.y = obj["size"][1];
		return true;
	}
}

bool Texture::FillScale(const nlohmann::json& obj, float& scale)
{
	if (obj["scale"].is_null()) {
		return false;
	}
	else {
		scale += obj["scale"];
		return true;
	}
	
}

bool Texture::FillStates(const nlohmann::json& obj, std::vector<texture_state>& states)
{
	/*Check if the state array exists*/
	if (obj["states"].is_null()) {
		return false;
	}
	else if (obj["states"].size() == 0) {
		return false;
	}
	/*Get the states*/
	else {
		for (auto s : obj["states"]) {
			texture_state state_obj;
			/*Add the name*/
			if (s["name"].is_null()) {
				return false;
			}
			else {
				state_obj.name = s["name"];
			}
			/*Add the duration*/
			if (s["duration"].is_null()) {
				return false;
			}
			else {
				state_obj.duration = s["duration"];
			}
			/*Add the frames*/
			if (s["frames"].is_null()) {
				return false;
			}
			else {
				for (auto f : s["frames"]) {
					if (f.size() != 2) {
						return false;
					}
					else {
						state_obj.frames.push_back(olc::vi2d(f[0], f[1]));
					}
				}
			}
			/*Added everything to the local variable, now push it back*/
			states.push_back(state_obj);
		}
		return true;
	}
	return false;
}
