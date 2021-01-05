#pragma once
#include "olcPixelGameEngine.h"
class HitBox
{
public:
	/*This determines the colour of the hitbox, when it is drawn (for debug purposes)*/
	olc::Pixel colour;
	/*Offset from the CenterPosition of the Object*/
	olc::vf2d Offset;
};

