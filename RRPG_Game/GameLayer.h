#pragma once
#include "Layer.h"
#include "Map.h"
/*This is were the magic happens...*/

class GameLayer :
	public Layer
{
public:
	GameLayer(
		int layerid,
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() override;
	virtual StateType Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
	virtual std::shared_ptr<LayerPM> GetLayerPM() override;


	std::unique_ptr<AnimatedGameTile> Player;
protected:
	virtual bool OnEnable() override;
	virtual bool OnDisable() override;
	virtual void OnDraw(float fElapsedTime) override;
	virtual StateType HandleEvents() override;
	std::vector<std::unique_ptr<Map>> maps;
	std::unique_ptr<Map> currentMap;
	/*Just use an animated tile for now*/
	
};

