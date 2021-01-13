#pragma once
#include "GameObject.h"
#include "ButtonEvent.h"
#include "ButtonType.h"

/* A Button is a Game Object with an arbitrary size.
   The Button Hitbox is always ist size.
   It is represented as a Spritesheet and has to contain exactly three Sprites with dimensions of width*height.
 */
class Button :
	public GameObject
{
public:
    enum ButtonState {
        BUTTON_IDLE = 0,
        BUTTON_PRESSED = 1,
        BUTTON_MOUSEOVER = 2,
        BUTTON_RELEASED = 3
    };
public:
    Button(
        std::string path,
        int width,
        int height,
        olc::vf2d pos = { 0.0f, 0.0f }
    );
    virtual void Draw(float fElapsedTime) override;
    virtual std::shared_ptr<Event> Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
    ButtonState GetState() const;

    /*Event Setup Routines*/
    void setReleaseEvent(EventType::etype in_type);
    void setMOEvent(EventType::etype in_type);

protected:
    EventType GetEventType() const;
protected:
    int Width;
    int Height;
    ButtonState State;
    EventType::etype InvokedOnRelease;
    EventType::etype InvokedOnMouseOver;
    std::unique_ptr<olc::Renderable> image;
private:
    const olc::vf2d drawing_pos;
};