#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Gif
{
private: 
	sf::Vector2i size;
	sf::Clock clock;
	sf::Time startTime;
	sf::Time totalDelay;
	std::vector<std::tuple<int, sf::Texture>> frames;
	std::vector<std::tuple<int, sf::Texture>>::iterator framesIter;
public:
	Gif(const char* _path);
	void Update(sf::Sprite& _sprite);
	sf::Vector2i GetSize() const;
};

