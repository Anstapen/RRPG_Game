#pragma once
#include <memory>
#include <string>
#include "olcPixelGameEngine.h"
class PackingManager : public olc::PGEX
{
public:
	enum class PackingStyle {
		DEFAULT = -1,
		BLANK = 0,
		TITLE_SCREEN = 1,
		MAIN_GAME = 2,
		DEBUG_SCREEN = 3
	};
public:
	const std::string sBasePath;
	const PackingStyle sPackingStyle;
protected:
	PackingManager(
		std::string in_base_path = std::string(),
		PackingStyle in_pack_type = PackingStyle::DEFAULT
	);
};

