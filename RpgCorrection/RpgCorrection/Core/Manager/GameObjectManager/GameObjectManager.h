#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <vector>

namespace Core
{
	class GameObject;
	class Window;
	namespace Manager
	{
		class GameObjectManager : public Utils::Singleton<GameObjectManager>
		{
			DECLARE_CLASS_INFO(GameObjectManager, Singleton<GameObjectManager>)
#pragma region f/p
		private:
			std::vector<GameObject*> gameobjects = std::vector<GameObject*>();
			std::vector<GameObject*> requestedDestroyObject = std::vector<GameObject*>();
#pragma endregion
#pragma region methods
		private:
			void CheckCollision();
		public:
			void DestroyGameObject(GameObject* _item);
			void Register(GameObject* item);
			void UnRegister(GameObject* item);
			void DestroyAllRequest();
			void Update();
			void Draw(Window* _window);
			void OnDestroy() override;
#pragma endregion

		};
	}
}

