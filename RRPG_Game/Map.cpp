#include "Map.h"
#include "csv.h"
#include "GameTile.h"
#include <cmath>

Map::Map() :
	width(0),
	height(0),
	map_ids(),
	CameraPostion(((pge->ScreenWidth() / 2) / 24) - 12, ((pge->ScreenHeight() / 2) / 24) - 12 )
{
	
}

bool Map::LoadMap(MAP_ID in_id)
{
	/*Load map depending on map id*/
	switch (in_id) {
	default:
		LoadMap("./maps/Base_Map/Base_Map.csv", "./maps/Base_Map/Base_Map_Tileset.csv", 100, 100);
		break;
	}
	return false;
}

void Map::Update(float fElapsedTime, olc::vf2d player_pos)
{
	/*Update Camera Postion*/
	this->CameraPostion = player_pos;
	/*Clamp Camera if neccessary*/
	if (this->CameraPostion.x > this->width - 20) {
		this->CameraPostion.x = this->width - 20;
	}
	if (this->CameraPostion.x < 20) {
		this->CameraPostion.x = 20;
	}
	if (this->CameraPostion.y > this->height - 12) {
		this->CameraPostion.y = this->height - 12;
	}
	if (this->CameraPostion.y < 12) {
		this->CameraPostion.y = 12;
	}
	for (int i = 0; i < this->tiles.size(); i++) {
		/*TODO: used a real eventlist here*/
		this->tiles[i]->Update(fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>>());
	}
}

void Map::Draw(float fElapsedTime)
{
	/*Calculate the fist tile to be drawn*/
	olc::vi2d tile = { (int)(this->CameraPostion.x - 20.0f), (int)(this->CameraPostion.y - 12.0f) };
	float x_offset = this->CameraPostion.x - (float)ceil(this->CameraPostion.x);
	float y_offset = this->CameraPostion.y - (float)ceil(this->CameraPostion.y);
	for (int y = 0; y < (int)this->CameraPostion.y+12; y++) {
		for (int x = 0; x < (int)this->CameraPostion.x+20; x++) {
			this->tiles[this->map_ids[x][y]].get()->SetPosition({(float)x - x_offset, (float)y - y_offset});
			this->tiles[this->map_ids[x][y]].get()->Draw(fElapsedTime);
		}
	}
}

bool Map::LoadMap(std::string map_cfg, std::string tileset_cfg, unsigned int in_width, unsigned int in_height)
{
	this->height = in_height;
	this->width = in_width;
	/*Fill the Map using the cfg file and the TileSet*/
	/*Create Tileset*/
	TileSet tileSet(0, tileset_cfg);
	/*Read Config csv and populate tileset object*/
	tileSet.ReadConfig();
	/*Duplicate tiles from tileset*/
	FillTiles(tileSet);
	/*Read CSV line by Line*/
	io::LineReader in(map_cfg);
	std::string line;
	for (int i = 0; i < this->height; i++) {
		/*Read next line from csv*/
		line = in.next_line();
		if (line.empty()) {
			break;
		}
		this->map_ids.push_back(GetVecFromLine(line, tileSet));
	}
	/*Print vector size for Testing purposes*/
	std::cout << "Vector size: " << this->map_ids.size() << std::endl;
	return false;
}

std::vector<int> Map::GetVecFromLine(std::string line, TileSet& ts)
{
	std::vector<int> ret_vector;
	std::string s_number;
	unsigned int ts_size = ts.GetSize();
	int number;
	/*Iterate through string*/
	int i = 0;
	while(i < line.size()) {
		/*Check for last number in string*/
		if (i >= line.size() - 2) {
			number = std::stoi(line.substr(i));
			ret_vector.push_back(number);
			break;
		}
		/*Get the number*/
		number = std::stoi(line.substr(i, 3));
		/*Only push positive Nuumbers*/
		if (number < 0) {
			ret_vector.push_back(1);
			i += 3;
		}
		else if (number >= ts_size) {
			ret_vector.push_back(1);
			i += 2;
		}
		else {
			ret_vector.push_back(number);
			i += 2;
		}
	}
	return ret_vector;
}

bool Map::FillTiles(TileSet& ts)
{
	for (int i = 0; i < ts.GetSize(); i++) {
		this->tiles.push_back(ts.getTile((unsigned int)i));
	}
	return false;
}
