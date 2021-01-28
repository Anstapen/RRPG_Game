#pragma once
#include "ActorComponent.h"
#include "olcPixelGameEngine.h"
#include "Texture.h"
#include <string>

/*Smart Pointer for a Renderable*/
typedef std::shared_ptr<Texture> StrongTexturePtr;
/*Lets use a map for now, should be search that often...*/
typedef std::map<std::string, StrongTexturePtr>  TextureMap;
typedef std::pair<std::string, StrongTexturePtr> TexturePair;

class ITextureComponent :
    public ActorComponent
{
public:
    ActorComponentId GetID(void) const override;
    virtual bool Init(void) = 0;
    /*Draws all the active textures*/
    virtual void Draw(float fElapsedTime, olc::vf2d pos) = 0;
    /*Add a texture that should be drawn*/
    virtual void AddTexture(std::string name) = 0;
    /*Remove a texture with the name*/
    virtual void RemoveTexture(std::string name) = 0;
    /*Enable a texture*/
    virtual void Enable(std::string name) = 0;
    /*Disable a texture*/
    virtual void Disable(std::string name) = 0;
    /*Set state of texture*/
    virtual void SetState(std::string name, std::string new_state) = 0;
protected:
    const static ActorComponentId unique_id;
};