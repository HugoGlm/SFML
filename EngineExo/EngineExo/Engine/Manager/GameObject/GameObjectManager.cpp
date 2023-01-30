#include "GameObjectManager.h"
#include "../../GameObject/GameObject.h"

void Engine::Manager::GameObjectManager::Register(GameObject* _object)
{
	gameobjects.push_back(_object);
}
void Engine::Manager::GameObjectManager::UnRegister(GameObject* _object)
{
	std::erase(gameobjects, _object);
}
void Engine::Manager::GameObjectManager::Update()
{
	for (GameObject* _gameobject : gameobjects)
	{
		for (Component* _component : _gameobject->Components())
		{
			if (_component->enabled)
			{
				Reflection::MethodInfo<void>* _method = _component->GetFunction<void>("update");
				if (_method == nullptr)
					continue;
				_method->Invoke(_component);
			}
		}
	}
}

void Engine::Manager::GameObjectManager::OnDestroy()
{
	for (GameObject*& _gameobject : gameobjects)
	{
		delete _gameobject;
		_gameobject = nullptr;
	}
	gameobjects.clear();
}
