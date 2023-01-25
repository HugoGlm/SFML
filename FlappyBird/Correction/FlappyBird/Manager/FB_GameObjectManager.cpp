#include "FB_GameObjectManager.h"
#include "../GameObject/GameObject.h"

#pragma region methods
void FB_GameObjectManager::Register(GameObject* _gameObject)
{
	gameobjects.push_back(_gameObject);
}
void FB_GameObjectManager::UnRegister(GameObject* _gameObject)
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (gameobjects[i] == _gameObject)
		{
			gameobjects.erase(gameobjects.begin() + i);
			break;
		}
	}
}
void FB_GameObjectManager::Update()
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		gameobjects[i]->OnUpdate();
	}
}
void FB_GameObjectManager::Destroy(GameObject* _gameObject)
{
	objectToDestroy.push_back(_gameObject);
}
void FB_GameObjectManager::Draw(Window* _window)
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		gameobjects[i]->OnDraw(_window);
	}
}
void FB_GameObjectManager::CheckCollision()
{
	for (GameObject* _a : gameobjects)
	{
		for (GameObject* _b : gameobjects)
		{ 
			if (_a == _b || !_a->GetGlobalBounds().contains(_b->Position()))
				continue;
			_b->OnCollisionEnter(_a);
		}
	}
}
void FB_GameObjectManager::DestroyAllRequests()
{
	for (GameObject* _object : objectToDestroy)
	{
		UnRegister(_object);
	}
	objectToDestroy.clear();
}
void FB_GameObjectManager::DestroyAllObjects()
{
	for (GameObject* _object : gameobjects)
	{
		delete _object;
		_object = nullptr;
	}
	objectToDestroy.clear();
	gameobjects.clear();
}
#pragma endregion

#pragma region override
void FB_GameObjectManager::OnDestroy()
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
		delete gameobjects[i];
	gameobjects.clear();
}
#pragma endregion

