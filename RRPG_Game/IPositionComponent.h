#pragma once
#include "ActorComponent.h"
#include "olcPixelGameEngine.h"
class IPositionComponent :
    public ActorComponent
{
public:
    ActorComponentId GetID(void) const override;
    /*These Functions have to be implemented*/
    virtual bool Init(void) = 0;
    virtual olc::vf2d GetPosition(void) = 0;
    virtual void SetPosition(olc::vf2d new_pos) = 0;
protected:
    const static ActorComponentId unique_id;
};