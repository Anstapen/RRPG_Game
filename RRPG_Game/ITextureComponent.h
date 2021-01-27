#pragma once
#include "ActorComponent.h"
#include "olcPixelGameEngine.h"

/*Smart Pointer for a Renderable*/
typedef std::shared_ptr<olc::Renderable> StrongRenderablePtr;
/*Lets use a map for now, should be search that often...*/
typedef std::map<std::string, StrongRenderablePtr> RenderableMap;
typedef std::pair<std::string, StrongRenderablePtr> RenderablePair;

class ITextureComponent :
    public ActorComponent
{
public:
    ActorComponentId GetID(void) const override;
    virtual bool Init(void) = 0;
    /*Provides the texture, depending on the given state*/
    virtual void Draw(float fElapsedTime, olc::vf2d pos) = 0;
    /*Add a texture that should be drawn*/
    virtual void AddTexture(RenderablePair in_pair) = 0;
    virtual void RemoveTexture(std::string name) = 0;
protected:
    const static ActorComponentId unique_id;
};