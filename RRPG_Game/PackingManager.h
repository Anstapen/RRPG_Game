#pragma once
#include <memory>
#include <string>
#include "olcPixelGameEngine.h"
class PackingManager : public olc::PGEX
{
public:
	std::string sBasePath;
	std::string sPackingType = "default";
};

