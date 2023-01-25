#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Core
{
	class Gif : public Object
	{
		DECLARE_CLASS_INFO(Gif, Object)
#pragma region f/p
	private:
		sf::Vector2i size = sf::Vector2i(0, 0);
		sf::Clock clock = sf::Clock();
		sf::Time startTime = sf::Time();
		sf::Time totalDelay = sf::Time();
		std::vector<std::tuple<int, sf::Texture>> frames = std::vector<std::tuple<int, sf::Texture>>();
		std::vector<std::tuple<int, sf::Texture>>::iterator frameIterator;
#pragma endregion
#pragma region constructor
	public:
		Gif() = delete;
		Gif(const char* _path);
#pragma endregion
#pragma region methods
	public:
		void update(sf::Sprite& _sprite);
		sf::Vector2i GetSize() const;
#pragma endregion

	};
}

