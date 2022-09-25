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
    /*TextureMap::iterator it;
    for (it = texture_map->begin(); it != texture_map->end(); it++) {
        it->second->Draw(fElapsedTime, pos);
    }*/
    /*iterate through using the prio list*/
    std::vector<std::string>::iterator it;
    /*Reverse iterate through the prio list*/
    for (it = this->prio_list.begin(); it != this->prio_list.end(); it++) {
        this->texture_map->at(*(it))->Draw(fElapsedTime, pos);
    }
}


/*TODO: can improve this function*/
void MultiTexture::AddTexture(std::string name)
{
    /*Check if there is already a texure with the given name*/
    bool exists = false;
    try {
        this->texture_map->at(name);
    }
    catch (const std::out_of_range& er) {
        exists = true;
    }
    /*if it exists, delete the texture*/
    if (exists) {
        this->texture_map->erase(name);
    }
    /*Create Texture*/
    Texture tex(name);
    /*Check if the texture was created correctly*/
    if (tex.isValid()) {
        this->texture_map.get()->insert(std::pair<std::string, StrongTexturePtr>(name, std::make_shared<Texture>(std::move(tex))));
        this->prio_list.push_back(name);
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

void MultiTexture::SetState(std::string new_state)
{
    TextureMap::iterator it;
    for (it = texture_map->begin(); it != texture_map->end(); it++) {
        it->second->SetState(new_state);
    }
}
