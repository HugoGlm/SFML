#pragma once
#include "../../../Core/GameObject/GameObject.h"

namespace Game
{
	namespace Interface
	{
		class IInteractable :public Core::GameObject
		{
			DECLARE_CLASS_INFO(IInteractable, GameObject)
#pragma region constructor
		public:
			IInteractable();
			~IInteractable() override;
#pragma endregion
#pragma region methods
		public:
			virtual void OnIteract(class Player* _player) = 0;
#pragma endregion

		};
	}
}

