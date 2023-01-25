#pragma once
#include "../../Base/BaseSpell.h"

namespace Game
{
	namespace Spell
	{

		class FireBallSpell : public BaseSpell
		{
			DECLARE_CLASS_INFO(FireBallSpell, BaseSpell)
#pragma region f/p
		private:
			Entity::Entity* owner = nullptr;
#pragma endregion
#pragma region constructor
		public:
			FireBallSpell(Entity::Entity* _entity);
#pragma endregion
#pragma region override
		public:
			void OnUse() override;
#pragma endregion

		};
	}
}

