#include "Cursor.h"

Cursor::Cursor(std::string path, int width, int height, olc::vf2d scaling) :
	GameObject(olc::vf2d((480 / 2) + (width*scaling.x / 2), (288 / 2) + (height*scaling.y / 2))),
	Height(height),
	Width(width),
	Active(true),
	State(Cursor::CursorState::CURSOR_IDLE),
	Scaling(scaling),
	CursorPosition(olc::vi2d(480/2, 288/2)),
	image(std::make_unique<olc::Renderable>())
{
	/*Load the PNG*/
	this->image.get()->Load(path);
}

void Cursor::Draw(float fElapsedTime)
{
	olc::vf2d src_index = { (float)Width * this->State, 0.0f };
	/*Draw the Sprite/Decal depending on the Cursor State*/
	pge->DrawPartialDecal(this->CursorPosition, this->image.get()->Decal(), src_index, olc::vf2d(Width, Height), this->Scaling);
}

void Cursor::Update(float fElapsedTime)
{
	/*Check if any of the three Mouse Buttons is pressed*/
	if (pge->GetMouse(0).bHeld || pge->GetMouse(1).bHeld || pge->GetMouse(2).bHeld) {
		this->State = Cursor::CursorState::CURSOR_PRESSED;
	}
	else {
		this->State = Cursor::CursorState::CURSOR_IDLE;
	}
	/*Update Location of the Mouse Cursor*/
	this->CursorPosition = { pge->GetMouseX(), pge->GetMouseY() };
	/*Update Center of the Cursor Sprite (not used at all atm)*/
	this->CenterPosition = { this->CursorPosition.x + (Width * Scaling.x / 2), this->CursorPosition.y + (Height * Scaling.y / 2) };
}

