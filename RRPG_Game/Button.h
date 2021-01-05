#pragma once
#include "GameObject.h"

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
    virtual void CheckState();
    virtual void Draw(float fElapsedTime) override;
    ButtonState GetState() const;

protected:
    int Width;
    int Height;
    ButtonState State;
    std::unique_ptr<olc::Renderable> image;
};