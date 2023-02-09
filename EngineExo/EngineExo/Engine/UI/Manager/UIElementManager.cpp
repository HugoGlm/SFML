#include "UIElementManager.h"
#include "../UIElement.h"

Engine::Manager::UIElementManager::UIElementManager(const UIElementManager&) = default;

#pragma region methods
void Engine::Manager::UIElementManager::Register(UIElement* _element)
{
	elements.push_back(_element);
}
void Engine::Manager::UIElementManager::UnRegister(UIElement* _element)
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (elements[i] == _element)
		{
			elements.erase(elements.begin() + 1);
			break;
		}
	}
}
void Engine::Manager::UIElementManager::Update()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		elements[i]->OnUpdate();
	}
}
#pragma endregion

#pragma region override
void Engine::Manager::UIElementManager::OnDestroy()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		delete elements[i];
	elements.clear();
}
#pragma endregion

