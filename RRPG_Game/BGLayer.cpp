#include "BGLayer.h"
#include "BGLayerPM.h"

BGLayer::BGLayer(int layerid, int width, int height, std::string path, olc::Pixel in_colour) :
	Layer(layerid),
	sprImage(std::make_unique<olc::Sprite>(width, height)),
	colour(in_colour)
{
	/*Depending on the path argument, either load the PNG or use an artifical Colour*/
	if (path.empty()) {
		/*Use the colour for the background*/
		PaintBG(width, height, colour);
	}
	else {
		/*Try to load the PNG File*/
		olc::rcode return_code = this->sprImage.get()->LoadFromFile(path);
		if (return_code != olc::OK) {
			/*File Load failed...use the coulour background*/
			PaintBG(width, height, colour);
		}
	}
	/*Assign the Sprite*/
	this->decImage = std::make_unique<olc::Decal>(this->sprImage.get());
}

void BGLayer::Setup()
{
}

void BGLayer::Draw(float fElapsedTime)
{
	pge->SetDrawTarget(this->ID);
	pge->DrawDecal(olc::vf2d(0.0f, 0.0f), this->decImage.get());
	pge->SetDrawTarget(nullptr);
}

bool BGLayer::OnEnable()
{
	return true;
}

bool BGLayer::OnDisable()
{
	return true;
}

void BGLayer::PaintBG(int width, int height, olc::Pixel colour)
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			this->sprImage.get()->SetPixel(x, y, colour);
		}
	}
}

void BGLayer::Update(float fElapsedTime)
{
}

std::shared_ptr<LayerPM> BGLayer::GetLayerPM()
{
	return std::shared_ptr<LayerPM>(new BGLayerPM());
}
