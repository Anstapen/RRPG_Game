#include "AppLayer.h"


/*Init the static variables*/

std::string AppLayer::actorFileName = "Actors.json";

std::string AppLayer::jsonBasePath = "JSON";

std::string AppLayer::textureFileName = "Textures.json";

std::string AppLayer::texturePath = "gfx";

float AppLayer::fElapsedTime = 0.0f;



void AppLayer::SetJsonPath(std::string new_path)
{
	AppLayer::jsonBasePath = new_path;
}

std::string AppLayer::GetJsonPath(void)
{
	return AppLayer::jsonBasePath;
}

void AppLayer::SetTextureFileName(std::string new_name)
{
	AppLayer::textureFileName = new_name;
}

std::string AppLayer::GetTextureFileName(void)
{
	return AppLayer::textureFileName;
}

void AppLayer::SetActorFileName(std::string new_name)
{
	AppLayer::actorFileName = new_name;
}

std::string AppLayer::GetActorFileName(void)
{
	return AppLayer::actorFileName;
}

void AppLayer::SetTexturePath(std::string new_path)
{
	AppLayer::texturePath = new_path;
}

std::string AppLayer::GetTexturePath(void)
{
	return AppLayer::texturePath;
}

float AppLayer::GetElapsedTime(void)
{
	return AppLayer::fElapsedTime;
}
