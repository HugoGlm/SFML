#pragma once
#include <SFML/Graphics.hpp>

class Input
{
public: 
	static bool IsKeyDown(const sf::Keyboard::Key& _key);
	static bool IsKeyUp(const sf::Keyboard::Key& _key);
};

