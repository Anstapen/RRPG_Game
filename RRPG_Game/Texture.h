#pragma once
#include <memory>
#include "olcPGEX_AnimatedSprite.h"
#include "json.hpp"
class Texture
{
private:

	/*subclass to help with the json deserialization*/
	class texture_state {
	public:
		std::string name = "";
		float duration = 0.1f;
		std::vector<olc::vi2d> frames;
	};


public:
	Texture(std::string name = "default"); 
	virtual ~Texture() = default;
	/*Custom copy constructors*/
	Texture(const Texture&);
	Texture& operator=(const Texture&) = delete;
	/*Custom move*/
	Texture(Texture&& other);
	Texture& operator=(Texture&& other) = delete;

	/*Inline Getters*/
	bool isValid() { return this->valid; }
	bool isActive() { return this->active; }

	/*Setters for the active variable*/
	void Enable(void) { this->active = true; }
	void Disable(void) { this->active = false; }

	/*Bread and Butter Functions*/
	virtual void SetState(std::string new_state);
	virtual void Draw(float fElapsedTime, olc::vf2d pos);
	
protected:
	std::unique_ptr<olc::AnimatedSprite> image;
	std::unique_ptr<olc::Renderable> src;
	const std::string name;
	bool valid;
	bool active;

	virtual bool loadTexture(std::string name);


private:
	/*private helper functions for the texture loading*/
	bool FillPath(const nlohmann::json &obj, std::string &path);
	bool FillSize(const nlohmann::json & obj, olc::vi2d &vec);
	bool FillScale(const nlohmann::json & obj, float &scale);
	bool FillStates(const nlohmann::json & obj, std::vector<texture_state> &states);

};

