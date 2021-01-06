#pragma once
#include <string>
#include "olcPixelGameEngine.h"
#include "Layer.h"
#include "StateChanger.h"
/*This is the abstract State class.
  Every possible State the Game is in inherits from this class.
 */

class Layer;
class State : public olc::PGEX
{

public:
	std::string sName;
	std::string sPackingManagerPath;

public:
	State(std::string name);
	virtual ~State();
	virtual StateChanger Execute(float fElapsedTime) = 0;
	virtual std::string GetStateStringFromChanger(StateChanger state) = 0;
	virtual bool Setup() = 0;
	virtual void DrawContent(float fElapsedTime) = 0;
	virtual void ChangeState(int state_id) = 0;

protected:
	std::vector<std::shared_ptr<Layer>> Layers;
};