#pragma once
#include <vector>
#include <string>
#include "TileSet.h"
#include "MAP_ID.h"
/*A Map is a 2D Array of Tiles that gets generated once and remains unchanges through the Rest of the Game.*/
class Map : public olc::PGEX
{

public:
	Map();
	virtual bool LoadMap(MAP_ID in_id = MAP_ID::DEFAULT);
	virtual void Update(float fElapsedTime, olc::vf2d player_pos);
	virtual void Draw(float fElapsedTime);

protected:
	virtual bool LoadMap(std::string map_cfg, std::string tileset_cfg, unsigned int width, unsigned int height);
	int width;
	int height;
	std::vector<std::vector<int>> map_ids;
private:
	/*some little helper functions*/
	std::vector<int> GetVecFromLine(std::string line, TileSet& ts);
	bool FillTiles(TileSet& ts);
	std::vector<std::unique_ptr<GameTile>> tiles;
	/*Player Position in tile space*/
	olc::vf2d CameraPostion;
};