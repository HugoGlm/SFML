#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>

class GameObject : public Object
{
#pragma region f/p
public:
	sf::Drawable* drawable = nullptr;
#pragma endregion
#pragma region constructor
public:
	GameObject();
	GameObject(const GameObject& _copy);
	~GameObject() override;
#pragma endregion
#pragma region methods
public:
	virtual void OnUpdate();
	virtual void OnDraw(class Window* _window);
	virtual void OnCollisionEnter(GameObject* _other);
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	virtual sf::Vector2f Position() const = 0;
#pragma endregion

};

