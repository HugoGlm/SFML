#pragma once
#include "../Entity.h"

namespace Game
{
	namespace Entity
	{
		class Mob : public Entity
		{
			DECLARE_CLASS_INFO(Mob, Entity)
#pragma region f/p
		private:
			sf::Vector2f aPosition = sf::Vector2f(0, 0);
			sf::Vector2f bPosition = sf::Vector2f(0, 0);
			sf::Vector2f direction = sf::Vector2f(1, 0);
			sf::Vector2f nextPosition = sf::Vector2f(0, 0);
#pragma endregion
#pragma region constructor
		public:
			Mob() = delete;
			Mob(const char* _texture);
#pragma endregion
#pragma region methods
		private:
			void DestroyOnDie();
		public:
			virtual void OnPerformMovement();
			void OnUpdate() override;
			void SetInitialPosition(const sf::Vector2f& _position);
#pragma endregion

		};
	}
}

