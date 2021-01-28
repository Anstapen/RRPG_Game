#include "MultiTexture.h"

ActorComponent* MultiTexture::CreateMultiTexture()
{
    return new MultiTexture;
}

MultiTexture::MultiTexture() :
    texture_map(new TextureMap)
{
}

bool MultiTexture::Init(void)
{
    return true;
}

void MultiTexture::Draw(float fElapsedTime, olc::vf2d pos)
{
    TextureMap::iterator it;
    for (it = texture_map->begin(); it != texture_map->end(); it++) {
        it->second->Draw(fElapsedTime, pos);
    }
}


/*TODO: can improve this function*/
void MultiTexture::AddTexture(std::string name)
{
    /*Create Texture*/
    Texture tex(name);
    /*Check if the texture was created correctly*/
    if (tex.isValid()) {
        this->texture_map.get()->insert(std::pair<std::string, StrongTexturePtr>(name, std::make_shared<Texture>(std::move(tex))));
    }
    else {
        return;
    }
}

void MultiTexture::RemoveTexture(std::string name)
{
    this->texture_map->erase(name);
}

void MultiTexture::Enable(std::string name)
{
    this->texture_map.get()->at(name)->Enable();
}

void MultiTexture::Disable(std::string name)
{
    this->texture_map.get()->at(name)->Disable();
}

void MultiTexture::SetState(std::string name, std::string new_state)
{
    this->texture_map.get()->at(name)->SetState(new_state);
}
