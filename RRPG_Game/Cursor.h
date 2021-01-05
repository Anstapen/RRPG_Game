#pragma once
#include "GameObject.h"
class Cursor :
	public GameObject
{
public:
	enum CursorState {
		CURSOR_IDLE = 0,
		CURSOR_PRESSED = 1
	};
public:
	Cursor(
		std::string path,
		int width,
		int height,
		olc::vf2d scaling = {1.0f, 1.0f}
	);
	virtual void Draw(float fElapsedTime) override;
	virtual void Update(float fElapsedTime) override;
protected:
	bool Active;
	CursorState State;
	int Width;
	int Height;
	olc::vi2d CursorPosition;
	olc::vf2d Scaling;
	std::unique_ptr<olc::Renderable> image;
};

