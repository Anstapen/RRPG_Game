#pragma once
#include "Layer.h"
#include "olcPixelGameEngine.h"
#include "LayerPM.h"

/*
This is the Background Layer Class.
It always draws the complete Screen, either with a Color or with a Sprite.
*/
class BGLayer :
	public Layer
{
public:
	BGLayer(
		int layerid,
		int width,
		int height,
		std::string path = std::string(),
		olc::Pixel in_colour = olc::WHITE
	);
	virtual void Setup() override;
	virtual void Draw(float fElapsedTime) override;
	virtual StateChanger Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
	virtual std::shared_ptr<LayerPM> GetLayerPM() override;
protected:
	virtual bool OnEnable() override;
	virtual bool OnDisable() override;
	virtual StateChanger HandleEvents() override;
	std::unique_ptr<olc::Sprite> sprImage;
	std::unique_ptr<olc::Decal> decImage;
	olc::Pixel colour;
	virtual void PaintBG(int width, int height, olc::Pixel colour = olc::WHITE);
};

