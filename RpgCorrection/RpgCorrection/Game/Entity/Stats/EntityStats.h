#pragma once
#include "../../../Core/Object/Object.h"

namespace Game
{
	namespace Entity
	{
		struct EntityStats : Core::Object 
		{
			DECLARE_CLASS_INFO(EntityStats, Object)
#pragma region f/p
			static const EntityStats Default;
			float life = 100.0f;
			float maxLife = 100.0f;
			float mana = 100.0f;
			float maxMana = 100.0f;
			float speed = 10.0f;
#pragma endregion
#pragma region constructor
			EntityStats(float _life, float _maxLife, float _mana, float _maxMana, float _speed)
			{
				life = _life;
				maxLife = _maxLife;
				mana = _mana;
				maxMana = _maxMana;
				speed = _speed;
			}
			EntityStats(float _maxLife, float _maxMana, float _speed) 
				: self(_maxLife, _maxLife, _maxMana, _maxMana, _speed) {}
#pragma endregion

		};
	}
}