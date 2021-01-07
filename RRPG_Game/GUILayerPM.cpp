#include "GUILayerPM.h"
#include "GUILayer.h"
#include "Button.h"
#include "Cursor.h"

GUILayerPM::GUILayerPM(std::string in_base_path, PackingManager::PackingStyle in_pack_type) :
	LayerPM(in_base_path, in_pack_type)
{
}

bool GUILayerPM::PackLayer(std::shared_ptr<Layer> layer)
{
	/* Pack the GUI Layer with the TitleScreen Objects*/
	if(this->sPackingStyle == PackingManager::PackingStyle::TITLE_SCREEN){
		/*Add TitleScreen Buttons*/
		/*Add the "New Run" Button*/
		std::shared_ptr<Button> start_button = std::make_shared<Button>("./gfx/New_Run_Button.png", 50, 20, olc::vf2d(pge->ScreenWidth() / 2, ((pge->ScreenHeight() * 2) / 3)));
		start_button->setReleaseEvent(EventType::etype::CREATE_NEW_GAME);
		layer->AddObject(start_button);

		/* Add the "Debug" Button*/
		std::shared_ptr<Button> debug_button = std::make_shared<Button>("./gfx/Debug_Button.png", 50, 20, olc::vf2d(pge->ScreenWidth() / 2, ((pge->ScreenHeight() * 2) / 3) - 50));
		debug_button->setReleaseEvent(EventType::etype::SWITCH_TO_DEBUGSCREEN);
		layer->AddObject(debug_button);

		/*Adding the Main Cursor*/
		std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Cursor_RED.png", 13, 17, olc::vf2d(0.5f, 0.5f));
		layer->AddObject(main_cursor);
	}

	/* Pack the GUI Layer in a Debug Layout*/
	if (this->sPackingStyle == PackingManager::PackingStyle::DEBUG_SCREEN) {
		/* Add a "Test" Button*/
		std::shared_ptr<Button> test_button1 = std::make_shared<Button>("./gfx/Blue_Test_Button.png", 50, 20, olc::vf2d(300.0f, 120.0f));
		layer->AddObject(test_button1);
		/*Adding the Main Cursor*/
		std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Cursor_RED.png", 13, 17, olc::vf2d(0.5f, 0.5f));
		layer->AddObject(main_cursor);
	}

	/* Pack the GUI Layer for the MainGame*/
	if (this->sPackingStyle == PackingManager::PackingStyle::MAIN_GAME) {
		/*Adding the Main Cursor*/
		std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Cursor_RED.png", 13, 17, olc::vf2d(0.5f, 0.5f));
		layer->AddObject(main_cursor);
	}
	
	return true;
}