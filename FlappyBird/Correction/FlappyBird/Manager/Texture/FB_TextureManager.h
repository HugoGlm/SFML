#pragma once
#include "../../../Singleton/Singleton.h"
#include <SFML/Graphics.hpp>
#include <map>

class FB_TextureManager :public Singleton<FB_TextureManager>
{
#pragma region f/p
private:
	std::map<const char*, sf::Texture*> textures = std::map<const char*, sf::Texture*>();
#pragma endregion
#pragma region constructor
public:
	FB_TextureManager() = default;
#pragma endregion
#pragma region methods
public:
	sf::Texture* Get(const char* _path);
#pragma endregion
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion

};

