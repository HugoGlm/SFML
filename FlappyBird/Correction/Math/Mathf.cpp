#include "Mathf.h"

#pragma region methods
sf::Vector2f Mathf::Lerp(const sf::Vector2f& _from, const sf::Vector2f& _to, float _t)
{
	_t = Clamp01(_t);
	return sf::Vector2f(_from.x + (_to.x - _from.x) * _t, _from.y + (_to.y - _from.y) * _t);
}
#pragma endregion

