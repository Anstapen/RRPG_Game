#pragma once
#include "olcPixelGameEngine.h"
#include <memory>
#include "HitBox.h"
#include "Event.h"

/*A GameObject is a Renderable that is drawn ontop of the background.
  It has a Rederable Object(arbitrary size) that only belongs to it.
  It has a 2 dimensional position in form of a vf2d object.
 */
class GameObject : public olc::PGEX
{
public:
    GameObject(
        olc::vf2d pos = { 0.0f, 0.0f },
        std::list<HitBox> CombHitBox = std::list<HitBox>()
    );
    /* This Method draws the Object on the Screen and has to be implemented by the child class*/
    virtual void Draw(float fElapsedTime) = 0;
    virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) = 0;
    olc::vf2d GetPosition();
protected:
    /*The centered Position of the Object, 
    drawing position can be easily calculated because the Sprite is 24x24 px*/
    olc::vf2d CenterPosition;
    /* A list of Hitboxes around the CenterPostion of the Object. Empty list means: use complete Tile as hitbox*/
    std::list<HitBox> CombinedHitBox;
};