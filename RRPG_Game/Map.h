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
	/*Delete Copy constructor and copy assignment operator*/
	Map(const Map& other) = delete;
	Map& operator=(const Map& other) = delete;
	virtual bool LoadMap(MAP_ID in_id = MAP_ID::DEFAULT);
	virtual void Update(float fElapsedTime, olc::vf2d player_pos);
	virtual void Draw(float fElapsedTime);
protected:
	virtual bool LoadMap(std::string map_cfg, std::string tileset_cfg, std::string base_map, unsigned int width, unsigned int height);
	int width;
	int height;
	std::vector<std::vector<int>> map_ids;
	std::unique_ptr<olc::Renderable> base_map;
private:
	/*some little helper functions*/
	std::vector<int> GetVecFromLine(std::string line, TileSet& ts);
	bool FillTiles(TileSet& ts);
private:
	std::vector<std::unique_ptr<GameTile>> tiles;
	/*Camera Position in tile space*/
	olc::vf2d CameraPostion;
};