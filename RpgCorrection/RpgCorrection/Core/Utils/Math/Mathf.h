#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>
namespace Core
{
	namespace Utils
	{
		class Mathf : public Object
		{
			DECLARE_CLASS_INFO(Mathf, Object)
		public:
			static float Distance(const sf::Vector2f& _a, const sf::Vector2f& _b);
			static int Next(int _min, int _max);
			template<typename T>
			static T Clamp(T _value, T _min, T _max)
			{
				if (_value < _min) return _min;
				if (_value > _max) return _max;
				return _value;
			}
		};
	}
}