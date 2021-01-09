#include "TileSet.h"
#include "csv.h"

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
	while (in.read_row(path, isCollidable, isAnimated, NoOfFrames)) {
		std::cout << "Read New Line:" << std::endl;
		std::cout << "Path to PNG: " << path << std::endl;
		std::cout << "isCollidable: " << (isCollidable ? "True" : "False") << std::endl;
		std::cout << "isAnimated: " << (isAnimated ? "True" : "False") << std::endl;
		std::cout << "No. of Frames: " << NoOfFrames << std::endl;
	}
}