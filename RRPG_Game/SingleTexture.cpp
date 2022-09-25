#include "SingleTexture.h"

ActorComponent* SingleTexture::CreateSingleTexture()
{
	return new SingleTexture;
}

SingleTexture::SingleTexture() :
	texture_pair(nullptr)
{
}

bool SingleTexture::Init(void)
{
	return true;
}

void SingleTexture::Draw(float fElapsedTime, olc::vf2d pos)
{
	if (this->texture_pair != nullptr) {
		this->texture_pair->second->Draw(fElapsedTime, pos);
	}
}


/*This function only adds the texture if its empty*/
void SingleTexture::AddTexture(std::string name)
{
	if (this->texture_pair == nullptr) {
		Texture tex(name);
		if (tex.isValid()) {
			this->texture_pair = std::make_unique<TexturePair>(std::pair<std::string, StrongTexturePtr>(name, std::make_shared<Texture>(std::move(tex))));
		}
	}
}

void SingleTexture::RemoveTexture(std::string name)
{
	/*If the names match, erase the texture*/
	if (this->texture_pair != nullptr && this->texture_pair->first == name) {
		this->texture_pair.reset(nullptr);
	}
}

void SingleTexture::Enable(std::string name)
{
	if (this->texture_pair != nullptr && this->texture_pair->first == name) {
		this->texture_pair->second->Enable();
	}
}

void SingleTexture::Disable(std::string name)
{
	if (this->texture_pair != nullptr && this->texture_pair->first == name) {
		this->texture_pair->second->Disable();
	}
}

void SingleTexture::SetState(std::string name, std::string new_state)
{
	if (this->texture_pair != nullptr && this->texture_pair->first == name) {
		this->texture_pair->second->SetState(new_state);
	}
}

void SingleTexture::SetState(std::string new_state)
{
	if (this->texture_pair != nullptr) {
		this->texture_pair->second->SetState(new_state);
	}
}
