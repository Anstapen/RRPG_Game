#pragma once
#include "IPositionComponent.h"

/*This class holds the position on the screen, in aboslute pixel values
  The Position marks the CENTER of the Actor, drawing positions have to be calculated manually
*/
class ScreenPositionComponent :
    public IPositionComponent
{
public:
    /*Function for the Factory*/
    static ActorComponent* CreateScreenPosition();
public:
    virtual ~ScreenPositionComponent() = default;
    bool Init(void) override;
    olc::vf2d GetPosition(void) override;
    void SetPosition(olc::vf2d new_pos) override;
protected:
    ScreenPositionComponent();
private:
    olc::vf2d pos;
};

