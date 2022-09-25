#include "GUILayerPM.h"
#include "GUILayer.h"
#include "Button.h"
#include "Cursor.h"
#include "SimplePoly.h"
#include "Overlay.h"

GUILayerPM::GUILayerPM(std::string in_base_path, PackingManager::PackingStyle in_pack_type) :
	LayerPM(in_base_path, in_pack_type)
{
}

bool GUILayerPM::PackLayer(std::shared_ptr<Layer> layer)
{
	/*Cast the Object into an GUILayer Object.
	TODO: IF POSSIBLE; PLEASE AVOID CONDITIONAL DYNAMIC CAST!!!!!!*/
	std::shared_ptr<GUILayer> casted_layer = std::dynamic_pointer_cast<GUILayer>(layer);

	/* Pack the GUI Layer with the TitleScreen Objects*/
	if(this->sPackingStyle == PackingManager::PackingStyle::TITLE_SCREEN){
		

		/*Add TitleScreen Buttons*/
		/*Add the "New Run" Button*/
		std::shared_ptr<Button> start_button = std::make_shared<Button>("./gfx/New_Run_Button.png", 50, 20, olc::vf2d(pge->ScreenWidth() / 2, ((pge->ScreenHeight() * 2) / 3)));
		casted_layer->AddObject(start_button);

		/* Add the "Debug" Button*/
		std::shared_ptr<Button> debug_button = std::make_shared<Button>("./gfx/Debug_Button.png", 50, 20, olc::vf2d(pge->ScreenWidth() / 2, ((pge->ScreenHeight() * 2) / 3) - 50));
		casted_layer->AddObject(debug_button);

		/*Adding the Main Cursor*/
		std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Cursor_RED.png", 13, 17, olc::vf2d(0.5f, 0.5f));
		casted_layer->AddCursor(main_cursor);
	}

	/* Pack the GUI Layer in a Debug Layout*/
	if (this->sPackingStyle == PackingManager::PackingStyle::DEBUG_SCREEN) {
		/*Add the ESC Button*/
		std::shared_ptr<Button> esc_button = std::make_shared<Button>("./gfx/Esc_Button.png", 15, 15, olc::vf2d(20.0f, 20.0f));
		casted_layer->AddObject(esc_button);
		/* Add a "Test" Button*/
		std::shared_ptr<Button> test_button1 = std::make_shared<Button>("./gfx/Blue_Test_Button.png", 50, 20, olc::vf2d(300.0f, 120.0f));
		casted_layer->AddObject(test_button1);
		/*Adding the Main Cursor*/
		std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Cursor_RED.png", 13, 17, olc::vf2d(0.5f, 0.5f));
		casted_layer->AddCursor(main_cursor);
	}

	/* Pack the GUI Layer for the MainGame*/
	if (this->sPackingStyle == PackingManager::PackingStyle::MAIN_GAME) {
		/*Adding the Esc Button*/
		std::shared_ptr<Button> esc_button = std::make_shared<Button>("./gfx/Esc_Button.png", 15, 15, olc::vf2d(20.0f, 20.0f));
		casted_layer->AddObject(esc_button);
		/*Adding the Overlay*/
		std::shared_ptr<Overlay> maingame_overlay = std::make_shared<Overlay>("./gfx/MainGame_GUI_Overlay.png");
		casted_layer->AddObject(maingame_overlay);
		/*Adding the Main Cursor*/
		std::shared_ptr<Cursor> main_cursor = std::make_shared<Cursor>("./gfx/Cursor_RED.png", 13, 17, olc::vf2d(0.5f, 0.5f));
		casted_layer->AddCursor(main_cursor);
	}
	
	return true;
}