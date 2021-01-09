#include "TileSet.h"
#include "csv.h"
#include "AnimatedGameTile.h"
#include "StaticGameTile.h"

TileSet::TileSet(int in_DTI, std::string cfg) :
	ConfigFile(cfg),
	DefaultTileIndex(in_DTI)
{
}

void TileSet::ReadConfig()
{
	/*Iterate through CSV and load the GameTiles*/
	std::cout << "Reading Config File: " << this->ConfigFile << std::endl;
	io::CSVReader<4> in(this->ConfigFile);
	in.read_header(io::ignore_no_column, "path", "isCollidable", "isAnimated", "NoOfFrames");
	std::string path;
	int isCollidable;
	int isAnimated;
	unsigned int NoOfFrames;
	unsigned int tile_number;
	while (in.read_row(path, isCollidable, isAnimated, NoOfFrames)) {
		/*Depending on the CSV Line, create the correct gameTile*/
		if (isAnimated) {
			/*Create an AnimatedGameTile Object*/
			this->aTiles.push_back(std::make_unique<AnimatedGameTile>(path, NoOfFrames, 0.5f, false, olc::vf2d(0.0f, 0.0f), (bool)isCollidable));
			/*Add an index*/
			this->IndexMap.push_back(std::pair<TileSet::TYLE_TYPE, unsigned int>(TileSet::TYLE_TYPE::ANIMATED, (this->aTiles.size()-1)));
			std::cout << "Created AnimatedGameTile for Tile(" << path << ", " << (isCollidable ? "True" : "False") << ", " << (isAnimated ? "True" : "False") << ", " << NoOfFrames << ") " << std::endl;
		}
		else {
			/*Create a StaticGameTile Object*/
			this->sTiles.push_back(std::make_unique<StaticGameTile>(path, olc::vf2d(0.0f, 0.0f), (bool)isCollidable));
			this->IndexMap.push_back(std::pair<TileSet::TYLE_TYPE, unsigned int>(TileSet::TYLE_TYPE::STATIC, (this->sTiles.size() - 1)));
			std::cout << "Created StaticGameTile for Tile(" << path << ", " << (isCollidable ? "True" : "False") << ", " << (isAnimated ? "True" : "False") << ", " << NoOfFrames << ") " << std::endl;
		}
	}
	std::cout << "Read " << (this->aTiles.size() + this->sTiles.size()) << "/" << this->IndexMap.size() << " Tiles..." << std::endl;
}

std::unique_ptr<GameTile> TileSet::getTile(unsigned int index)
{
	std::unique_ptr<GameTile> ret_tile = nullptr;
	/*Check vector boundary*/
	if (index >= this->IndexMap.size()) {
		/*Index out of bounds, return nullptr*/
		return ret_tile;
	}
	if (this->IndexMap[index].first == TileSet::TYLE_TYPE::ANIMATED) {
		/*Create an Animated Tile Object*/
		//AnimatedGameTile t(*(this->aTiles[this->IndexMap[index].second].get()));
		std::unique_ptr<GameTile> ret_tile = std::make_unique<AnimatedGameTile>(*(this->aTiles[this->IndexMap[index].second].get()));
		//std::unique_ptr<AnimatedGameTile> ret_tile = std::make_unique<AnimatedGameTile>(this->aTiles[this->IndexMap[index].second].get());
		return std::move(ret_tile);
	}
	else if (this->IndexMap[index].first == TileSet::TYLE_TYPE::STATIC) {
		/*Create a Static Tile Object*/
		//StaticGameTile t(*(this->sTiles[this->IndexMap[index].second].get()));
		std::unique_ptr<GameTile> ret_tile = std::make_unique<StaticGameTile>(*(this->sTiles[this->IndexMap[index].second].get()));
		//std::unique_ptr<StaticGameTile> ret_tile = std::make_unique<StaticGameTile>(const_cast<const AnimatedGameTile&>(*(this->aTiles[this->IndexMap[index].second].get())));
		return std::move(ret_tile);
	}
	else {
		return ret_tile;
	}
	return ret_tile;
	
}

unsigned int TileSet::GetSize()
{
	return this->IndexMap.size();
}
