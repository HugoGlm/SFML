#pragma once
#include <SFML/Graphics.hpp>

class Event
{
public:
	static inline sf::Event* currentEvent = nullptr;
};