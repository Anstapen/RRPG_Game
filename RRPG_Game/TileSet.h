#pragma once
#include "StaticGameTile.h"
#include "AnimatedGameTile.h"
/*A TileSet is a Set of Tiles(24x24) used for generating a Map.*/
class TileSet
{
public:
	TileSet(
		int in_DTI = 0,
		std::string cfg = std::string()
		);
	void ReadConfig();
	std::unique_ptr<GameTile> getTile(unsigned int index);
	unsigned int GetSize();
protected:
	enum class TYLE_TYPE {
		STATIC = 0,
		ANIMATED = 1
	};
	int DefaultTileIndex;
	std::string ConfigFile;
	/*Map the incoming index to one of the vectors*/
	std::vector<std::pair<TYLE_TYPE, unsigned int>> IndexMap;
	/*Array of GameTiles*/
	std::vector<std::unique_ptr<StaticGameTile>> sTiles;
	std::vector<std::unique_ptr<AnimatedGameTile>> aTiles;
};