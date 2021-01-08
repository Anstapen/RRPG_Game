#include "Ellipse.h"
#include <math.h>
#include <tgmath.h>



void CEllipse::Draw(float fElapsedTime)
{
	unsigned int y_mag;
	/* Iterate over a magnitude*/
	for (int i = a; i >= 0; i--) {
		 /* If i == a , we only dram +a and -a */
		/*if (i == a) {
			pge->Draw(GetAbsolutePos(i,0), olc::DARK_RED);
			pge->Draw(GetAbsolutePos((i * -1), 0), olc::DARK_RED);
		}*/
		//else {
			/*Draw the 4 pixels*/
			y_mag = GetYFromX(i);
			pge->Draw(GetAbsolutePos(i, y_mag), olc::DARK_RED);
			pge->Draw(GetAbsolutePos(i, (y_mag * -1)), olc::DARK_RED);
			pge->Draw(GetAbsolutePos((i * -1), y_mag), olc::DARK_RED);
			pge->Draw(GetAbsolutePos((i * -1), (y_mag * -1)), olc::DARK_RED);
		//}
	}
}

std::shared_ptr<Event> CEllipse::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	/*Update Postiton to mouse cursor*/
	this->CenterPosition = { (float)pge->GetMouseX(), (float)pge->GetMouseY() };
	if (pge->GetMouseWheel() > 0) {
		(this->a) += 2;
		(this->b)++;
		if (this->a < 0) this->a = 0;
		if (this->b < 0) this->b = 0;
		this->a_s = a * a;
		this->b_s = b * b;
	}
	if (pge->GetMouseWheel() < 0) {
		(this->a) -= 2;
		(this->b)--;
		if (this->a < 0) this->a = 0;
		if (this->b < 0) this->b = 0;
		this->a_s = a * a;
		this->b_s = b * b;
	}
	if (pge->GetMouse(2).bReleased) {
		this->a = 12;
		this->b = 5;
		this->a_s = a * a;
		this->b_s = b * b;
	}
	return std::shared_ptr<Event>();
}

CEllipse::CEllipse(olc::vf2d pos, unsigned int in_a, unsigned int in_b) :
	GameObject(pos),
	a(in_a),
	b(in_b)
{
	this->a_s = a * a;
	this->b_s = b * b;
}

unsigned int CEllipse::GetYFromX(float x)
{
	float sqr_y = (float)this->b_s - ((x*x) / (float)this->a_s) * (float)this->b_s;
	/*this variable contains the y postion, still in float*/
	float y = sqrt(sqr_y);
	unsigned int y_flat = ceil(y);
	return y_flat;
}

olc::vi2d CEllipse::GetAbsolutePos(int x, int y)
{
	return { (int32_t)CenterPosition.x + x, (int32_t)CenterPosition.y + y };
}
