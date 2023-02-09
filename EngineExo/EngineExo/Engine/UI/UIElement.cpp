#include "UIElement.h"
#include "Manager/UIElementManager.h"

#pragma region constructor
Engine::UIElement::UIElement(Window::EngineWindow* _window)
{
	owner = _window;
	Engine::Manager::UIElementManager::Instance()->Register(this);
}
Engine::UIElement::UIElement(const UIElement& _copy)
{
	owner = _copy.owner;
	isInteractable = _copy.isInteractable;
}
Engine::UIElement::~UIElement()
{
	Engine::Manager::UIElementManager::Instance()->UnRegister(this);
}
#pragma endregion
#pragma region methods
void Engine::UIElement::OnUpdate()
{
}
void Engine::UIElement::SetActive(const bool _status)
{
	isInteractable = _status;
}
#pragma endregion

