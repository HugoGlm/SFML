#pragma once
#include <SFML/Graphics.hpp>

class Mathf
{
#pragma region methods
public:
	static sf::Vector2f Lerp(const sf::Vector2f& _from, const sf::Vector2f& _to, float _t);
	template<typename T>
	static T Clamp01(const T _value);
#pragma endregion

};

template<typename T>
inline T Mathf::Clamp01(const T _value)
{
	if (_value < 0)
		return 0;
	if (_value > 1)
		return 1;
	return _value;
}
