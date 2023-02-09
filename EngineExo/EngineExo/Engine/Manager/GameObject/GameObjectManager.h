#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include "../../Window/Engine/EngineWindow.h"

namespace Engine
{
    class GameObject;
}
namespace Engine::Manager
{
    class GameObjectManager : public Utils::Singleton<GameObjectManager>
    {
        DECLARE_CLASS_INFO(GameObjectManager, Singleton<GameObjectManager>)
#pragma region var
    private:
        std::vector<GameObject*> gameobjects = std::vector<GameObject*>();
#pragma endregion
#pragma region constructor
    public:
        GameObjectManager() = default;
#pragma endregion
#pragma region methods
    public:
        void Register(GameObject* _object);
        void UnRegister(GameObject* _object);
        void Update() const;
        void Draw(const Window::EngineWindow* _window) const;
        void OnDestroy() override;
#pragma endregion

    };

}