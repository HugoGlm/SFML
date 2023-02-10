#include "UIElement.h"
#include "Manager/UIElementManager.h"

#pragma region constructor
Engine::UI::UIElement::UIElement(Window::EngineWindow* _window)
{
	owner = _window;
	Engine::UI::Manager::UIElementManager::Instance()->Register(this);
}
Engine::UI::UIElement::UIElement(const UIElement& _copy)
{
	owner = _copy.owner;
	isInteractable = _copy.isInteractable;
}
Engine::UI::UIElement::~UIElement()
{
	Engine::UI::Manager::UIElementManager::Instance()->UnRegister(this);
}
#pragma endregion
#pragma region methods
void Engine::UI::UIElement::OnUpdate()
{
}
void Engine::UI::UIElement::SetActive(const bool _status)
{
	isInteractable = _status;
}
#pragma endregion

