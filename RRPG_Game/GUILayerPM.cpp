#include "GUILayerPM.h"
#include "GUILayer.h"
#include "Button.h"
#include "Cursor.h"

bool GUILayerPM::PackLayer(std::shared_ptr<Layer> layer)
{
	/*Cast the Parent into the Child
	  TODO: VERY unsafe code... get rid of the raw pointer if possible...
	*/
	//std::shared_ptr<GUILayer> target(dynamic_cast<GUILayer*>(layer.get()));
	/*Add TitleScreen Buttons*/

	/*Add the "New Run" Button*/
	std::shared_ptr<Button> start_button = std::make_shared<Button>("./gfx/New_Run_Button.png", 50, 20, olc::vf2d(pge->ScreenWidth() / 2, ((pge->ScreenHeight() * 2) / 3)));
	layer->AddObject(start_button);


	/*Adding the Main Cursor*/
	std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Cursor_RED.png", 13, 17, olc::vf2d(0.5f, 0.5f));
	layer->AddObject(main_cursor);
	return true;
}