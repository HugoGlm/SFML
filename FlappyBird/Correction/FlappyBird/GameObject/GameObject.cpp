#include "GameObject.h"
#include "../../Window/Window.h"
#include "../Manager/FB_GameObjectManager.h"

#pragma region constructor
GameObject::GameObject()
{
	FB_GameObjectManager::Instance()->Register(this);
}
GameObject::GameObject(const GameObject& _copy)
{
	drawable = _copy.drawable;
}
GameObject::~GameObject()
{
	
}
#pragma endregion

#pragma region methods
void GameObject::OnUpdate() { }
void GameObject::OnDraw(Window* _window)
{
	_window->Draw(drawable);
}
void GameObject::OnCollisionEnter(GameObject* _other)
{
}
#pragma endregion

