#pragma once
#include "GameTile.h"
/*A TileSet is a Set of Tiles(24x24) used for generating a Map.*/
class TileSet
{
public:
	TileSet(
		int in_DTI = 0,
		std::string cfg = std::string()
		);
	void ReadConfig();
protected:
	int DefaultTileIndex;
	std::string ConfigFile;
	/*Array of GameTiles*/
	std::vector<GameTile> tiles;
};