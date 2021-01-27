#pragma once
#include "IPositionComponent.h"

/*A usable component that holds the position of the actor in the world space.
  IMPORTANT: This component saves the position as a tile value!
*/
class WorldPositionComponent :
    public IPositionComponent
{
public:
    /*The function for the Factory*/
    static ActorComponent* CreateWorldPosition();
public:
    virtual ~WorldPositionComponent() = default;
    /*Override the virtual parent functions*/
    bool Init(void) override;
    olc::vf2d GetPosition(void) override;
    void SetPosition(olc::vf2d new_pos) override;

protected:
    /*Default Constructor that sets the pos*/
    WorldPositionComponent();
private:
    olc::vf2d pos;
};