#include "Button.h"

Button::Button(std::string path, int width, int height, olc::vf2d pos) :
	GameObject(pos),
	Height(height),
	Width(width),
	State(Button::ButtonState::BUTTON_IDLE),
	image(std::make_unique<olc::Renderable>())
{

	/*Set up the Renderable*/
	this->image.get()->Load(path);
}

void Button::Draw(float fElapsedTime)
{
	/*calculate the drawing position*/
	olc::vf2d drawing_pos = { (this->CenterPosition.x - this->Width / 2), (this->CenterPosition.y - this->Height / 2) };
	/*Set the Sprite that will be drawn, depending on the Button State*/
	olc::vf2d src_pos = { (float)this->Width * this->State, 0 };
	if (src_pos.x > ((float)this->Width * 2)) {
		src_pos.x = ((float)this->Width * 2);
	}
	/*Draw the Sprite*/
	pge->DrawPartialDecal(drawing_pos, this->image.get()->Decal(), src_pos, olc::vf2d(this->Width, this->Height));
}

void Button::Update(float fElapsedTime)
{
	/*Change the Button State Depending on the Mouse Location*/
	olc::vi2d mouse_pos = { pge->GetMouseX(), pge->GetMouseY() };
	/*Check if the Mouse hovers over the Button*/
	if (mouse_pos.y >= this->CenterPosition.y - this->Height / 2 &&
		mouse_pos.y <= this->CenterPosition.y + this->Height / 2 &&
		mouse_pos.x >= this->CenterPosition.x - this->Width / 2 &&
		mouse_pos.x <= this->CenterPosition.x + this->Width / 2) {
		/*Check if, in additon to the mouse-over, the left mouse button is pressed*/
		if (pge->GetMouse(0).bHeld) {
			this->State = Button::ButtonState::BUTTON_PRESSED;
			//std::cout << "PRESSED\n";
		}
		else {
			this->State = Button::ButtonState::BUTTON_MOUSEOVER;
			//std::cout << "MOUSEOVER\n";
		}
	}
	else {
		this->State = Button::ButtonState::BUTTON_IDLE;
	}
	/*Check if the Button was Released*/
	if (this->State != Button::ButtonState::BUTTON_IDLE && pge->GetMouse(0).bReleased) {
		this->State = Button::ButtonState::BUTTON_RELEASED;
	}
}

Button::ButtonState Button::GetState() const
{
	return this->State;
}
