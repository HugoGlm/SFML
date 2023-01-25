#include "Mathf.h"
#include <random>

float Core::Utils::Mathf::Distance(const sf::Vector2f& _a, const sf::Vector2f& _b)
{
	const float _diffX = _a.x - _b.x;
	const float _diffY = _a.y - _b.y;
	return std::sqrt(_diffX * _diffX + _diffY * _diffY);
}

int Core::Utils::Mathf::Next(int _min, int _max)
{
	std::random_device _randomDevice;
	std::mt19937 _generation(_randomDevice());
	std::uniform_int_distribution _distrib(_min, _max);
	return _distrib(_generation);
}