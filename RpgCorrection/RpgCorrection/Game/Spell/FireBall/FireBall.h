#pragma once
#include "../../../Core/GameObject/GameObject.h"
#include "../../../Core/Gif/Gif.h"
#include "../../Entity/Entity.h"

namespace Game
{
	namespace Spell
	{
		class FireBall : public Core::GameObject
		{
			DECLARE_CLASS_INFO(FireBall, GameObject)
#pragma region f/p
		private:
			Core::Gif* gif = nullptr;
			Entity::Entity* owner = nullptr;
			sf::Vector2f direction = sf::Vector2f(1, 0);
			float speed = 100.0f;
			float lifeTime = 3.0f;
			float damage = 10.0f;
			sf::Clock clock = sf::Clock();
#pragma endregion
#pragma region constructor
		public:
			FireBall(Entity::Entity* _owner);
			~FireBall() override;
#pragma endregion
#pragma region methods
		public:
			void SetDirection(const sf::Vector2f& _direction);
			void SetDamage(const float _dmg);
#pragma endregion
#pragma region override
		public:
			void OnUpdate() override;
			void OnCollisionEnter(GameObject* _object) override;
#pragma endregion

		};
	}
}