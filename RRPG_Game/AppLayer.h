#pragma once
#include <string>

class AppLayer
{
public:
	/*Get/Set the Path to the folder containgin the json files*/
	static void SetJsonPath(std::string new_path);
	static std::string GetJsonPath(void);

	/*Get/Set the name of the json file that contains the texture config*/
	static void SetTextureFileName(std::string new_name);
	static std::string GetTextureFileName(void);

	/*Get/Set the name of the json file that contains the actor config*/
	static void SetActorFileName(std::string new_name);
	static std::string GetActorFileName(void);

	/*Get/Set the path to all the textures*/
	static void SetTexturePath(std::string new_path);
	static std::string GetTexturePath(void);

	/*Get the Elaopsed Time*/
	static float GetElapsedTime(void);
protected:
	/*The path of the folder that contains the json config files*/
	static std::string jsonBasePath;

	/*The filename of the texture config file*/
	static std::string textureFileName;

	/*the filename of the actor config file*/
	static std::string actorFileName;

	/*The path of all the textures*/
	static std::string texturePath;

	/*The elapsed time of the current frame*/
	static float fElapsedTime;
};

