#pragma once
#include "../../../Core/Object/Object.h"

namespace Game
{
	namespace Entity
	{
		class Entity;
	}
	namespace Spell
	{
		class BaseSpell : public Core::Object
		{
			DECLARE_CLASS_INFO(BaseSpell, Object)
#pragma region f/p
		private:
			std::string name = "default spell name";
			float cooldown = 5.0f;
			float currentCooldown = 0.0f;
			float manaCost = 1.0f;
			Game::Entity::Entity* owner = nullptr;
#pragma endregion
#pragma region constructor
		public:
			BaseSpell(const char* _name);
#pragma endregion
#pragma region mehods
		public:
			virtual void OnUse() = 0;
			float Cooldown() const;
			float ManaCost() const;
			bool IsInCooldown() const;
			std::string Name() const;
			Entity::Entity* Owner() const;
#pragma endregion

		};
	}
}

