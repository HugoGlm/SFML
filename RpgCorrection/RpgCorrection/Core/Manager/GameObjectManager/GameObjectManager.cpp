#include "GameObjectManager.h"
#include "../../GameObject/GameObject.h"
#include "../../Window/Window.h"

#pragma region methods
void Core::Manager::GameObjectManager::CheckCollision()
{
	for (GameObject* _a : gameobjects)
	{
		for (GameObject* _b : gameobjects)
		{
			if (_a == _b) continue;
			if (_a->GlobalBounds().intersects(_b->GlobalBounds()))
			{
				std::vector<GameObject*>& _collidedObject = _b->CollidedObject();
				if (std::ranges::find(_collidedObject, _a) == _collidedObject.end())
				{
					_collidedObject.push_back(_a);
					_b->OnCollisionEnter(_a);
				}
			}
			else
			{
				std::vector<GameObject*>& _collidedObject = _b->CollidedObject();
				const std::vector<GameObject*>::iterator& _index = std::ranges::find(_collidedObject, _a);
				if (_index != _collidedObject.end())
				{
					_collidedObject.erase(_index);
					_b->OnCollisionExit(_a);
				}
			}
		}
	}
}
void Core::Manager::GameObjectManager::DestroyGameObject(GameObject* _item)
{
	requestedDestroyObject.push_back(_item);
}
void Core::Manager::GameObjectManager::Register(GameObject* item)
{
	gameobjects.push_back(item);
}
void Core::Manager::GameObjectManager::UnRegister(GameObject* item)
{
	std::erase(gameobjects, item);
}
void Core::Manager::GameObjectManager::DestroyAllRequest()
{
	for (GameObject*& _object : requestedDestroyObject)
	{
		delete _object;
		_object = nullptr;
	}
	requestedDestroyObject.clear();
}
void Core::Manager::GameObjectManager::Update()
{
	CheckCollision();
	const std::vector<GameObject*> objects = gameobjects;
	for (GameObject* object : objects)
		object->OnUpdate();
}
void Core::Manager::GameObjectManager::Draw(Window* _window)
{
	const std::vector<GameObject*> objects = gameobjects;
	for (GameObject* object : objects)
		object->Draw(_window);
}
void Core::Manager::GameObjectManager::OnDestroy()
{
	for (GameObject*& gameobject : gameobjects)
	{
		if (gameobject == nullptr)
			continue;
		delete gameobject;
		gameobject = nullptr;
	}
	gameobjects.clear();
	requestedDestroyObject.clear();
}
#pragma endregion

