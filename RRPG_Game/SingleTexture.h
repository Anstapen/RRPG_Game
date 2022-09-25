#pragma once
#include "ITextureComponent.h"
class SingleTexture :
    public ITextureComponent
{
public:
    /*Function for the Factory*/
    static ActorComponent* CreateSingleTexture();
    SingleTexture();
    virtual bool Init(void) override;
    /*Draws all the active textures*/
    virtual void Draw(float fElapsedTime, olc::vf2d pos) override;
    /*Add a texture that should be drawn*/
    virtual void AddTexture(std::string name) override;
    /*Remove a texture with the name*/
    virtual void RemoveTexture(std::string name) override;
    /*Enable a texture*/
    virtual void Enable(std::string name) override;
    /*Disable a texture*/
    virtual void Disable(std::string name) override;
    /*Set state of texture*/
    virtual void SetState(std::string name, std::string new_state) override;
    /*Set state of all textures*/
    virtual void SetState(std::string new_state) override;
protected:
    std::unique_ptr<TexturePair> texture_pair;
};

