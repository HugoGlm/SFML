#pragma once
#include "../../Core/GameObject/GameObject.h"
#include "../Entity/Entity.h"
#include "../Spell/Base/BaseSpell.h"
#include "../Entity/Entity.h"
#include "../../Core/Input/Input.h"
#include <map>

namespace Game
{
	class Player : public Entity::Entity
	{
		DECLARE_CLASS_INFO(Player, Entity)
#pragma region f/p
	private:
		float jumpForce = 100.0f;
		std::map<Core::EKey, Spell::BaseSpell*> spells = std::map<Core::EKey, Spell::BaseSpell*>();
#pragma endregion
#pragma region constructor
	public:
		Player();
		Player(const Player& _copy);
		~Player() override;
#pragma endregion
#pragma region override
	public:
		void OnUpdate() override;
		void OnCollisionEnter(GameObject* _object) override;
#pragma endregion

	};
}

