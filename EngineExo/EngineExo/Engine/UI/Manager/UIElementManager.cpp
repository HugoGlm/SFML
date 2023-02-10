#include "UIElementManager.h"
#include "../UIElement.h"
#include "../../Window/Engine/EngineWindow.h"

Engine::UI::Manager::UIElementManager::UIElementManager(const UIElementManager&) = default;

#pragma region methods
void Engine::UI::Manager::UIElementManager::Register(UIElement* _element)
{
	elements.push_back(_element);
}
void Engine::UI::Manager::UIElementManager::UnRegister(UIElement* _element)
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
void Engine::UI::Manager::UIElementManager::Update() const
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		elements[i]->OnUpdate();
	}
}
void Engine::UI::Manager::UIElementManager::Draw(Window::EngineWindow* _window) const
{
	for (const UIElement* _object : elements)
		_object->Draw(_window);
}
void Engine::UI::Manager::UIElementManager::OnDestroy()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		delete elements[i];
	elements.clear();
}
#pragma endregion

