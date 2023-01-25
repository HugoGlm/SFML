#include "GameObject.h"
#include "../Utils/Debug/Debug.h"
#include "../Window/Window.h"
#include "../Manager/GameObjectManager/GameObjectManager.h"

#pragma region constructor
Core::GameObject::GameObject()
{
	sprite = new sf::Sprite();
	debugShape = new sf::RectangleShape();
	debugShape->setFillColor(sf::Color::Red);
	Manager::GameObjectManager::Instance()->Register(this);
}
Core::GameObject::GameObject(const GameObject& _copy)
{
	sprite = _copy.sprite;
	debugShape = _copy.debugShape;
	canDebug = _copy.canDebug;
	Manager::GameObjectManager::Instance()->Register(this);
}
Core::GameObject::~GameObject()
{
	Manager::GameObjectManager::Instance()->UnRegister(this);
	delete sprite;
	sprite = nullptr;
	delete debugShape;
	debugShape = nullptr;
}
#pragma endregion

#pragma region methods
void Core::GameObject::Destroy(GameObject* _object)
{
	Manager::GameObjectManager::Instance()->DestroyGameObject(_object);
}
std::vector<Core::GameObject*>& Core::GameObject::CollidedObject()
{
	return collidedObject;
}
void Core::GameObject::SetCanDebug(bool _status)
{
	canDebug = _status;
}
void Core::GameObject::SetPosition(const sf::Vector2f& _position)
{
	checkLow((sprite != nullptr), "[GameObject] => sprite is nullptr")
		sprite->setPosition(_position);
}
void Core::GameObject::SetOrigin(const sf::Vector2f& _origin)
{
	checkLow((sprite != nullptr), "[GameObject] => sprite is nullptr")
		sprite->setOrigin(_origin);
}
sf::Vector2f Core::GameObject::Position()
{
	check((sprite != nullptr), "[GameObject] => sprite is nullptr", sf::Vector2f(0, 0))
		return sprite->getPosition();
}
sf::Vector2f Core::GameObject::Origin() const
{
	check((sprite != nullptr), "[GameObject] => sprite is nullptr", sf::Vector2f(0, 0))
		return sprite->getOrigin();
}
bool Core::GameObject::IsValid() const
{
	return sprite != nullptr;
}
void Core::GameObject::Draw(Window* _window)
{
	checkLow((sprite != nullptr), "[GameObject] => sprite is nullptr")
		if (canDebug && debugShape != nullptr)
		{
			const sf::FloatRect _globalBounds = sprite->getGlobalBounds();
			debugShape->setSize(sf::Vector2f(_globalBounds.width, _globalBounds.height));
			debugShape->setPosition(Position());
			debugShape->setOrigin(Origin());
			_window->Draw(debugShape);
		}
	_window->Draw(sprite);
}
void Core::GameObject::OnUpdate() { }
void Core::GameObject::OnCollisionEnter(GameObject* _object) { }
void Core::GameObject::OnCollisionExit(GameObject* _object) { }
void Core::GameObject::SetScale(const sf::Vector2f& _scale)
{
	checkLow((sprite != nullptr), "[GameObject] => sprite is nullptr")
		sprite->setScale(_scale);
}
sf::Vector2f Core::GameObject::Scale() const
{
	check((sprite != nullptr), "[GameObject] => sprite is nullptr", sf::Vector2f(0, 0))
		return sprite->getScale();
}
sf::FloatRect Core::GameObject::GlobalBounds() const
{
	check((sprite != nullptr), "[GameObject] => sprite is nullptr", sf::FloatRect(0, 0, 0, 0))
		return sprite->getGlobalBounds();
}
#pragma endregion

