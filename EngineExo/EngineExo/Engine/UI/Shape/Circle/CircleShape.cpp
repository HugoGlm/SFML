#include "CircleShape.h"
#include "../../../Window/Engine/EngineWindow.h"

#pragma region constructor
Engine::UI::Shape::Circle::CircleShape::CircleShape(Window::EngineWindow* _owner, const float _size, sf::Vector2f _position) : UIElement(_owner)
{
	shape = new sf::CircleShape(_size);
	shape->setPosition(_position);
}
Engine::UI::Shape::Circle::CircleShape::CircleShape(const CircleShape& _copy) : UIElement(_copy)
{
	shape = _copy.shape;
}
Engine::UI::Shape::Circle::CircleShape::~CircleShape()
{
	delete shape;
	shape = nullptr;
	OnClick = nullptr;
}
#pragma endregion

#pragma region override
void Engine::UI::Shape::Circle::CircleShape::SetPosition(const sf::Vector2f& _position)
{
	shape->setPosition(_position);
}
void Engine::UI::Shape::Circle::CircleShape::SetScale(const sf::Vector2f& _scale)
{
	shape->setScale(_scale);
}
void Engine::UI::Shape::Circle::CircleShape::SetOrigin(const sf::Vector2f& _origin)
{
	shape->setOrigin(_origin);
}
void Engine::UI::Shape::Circle::CircleShape::Draw(Window::EngineWindow* _window) const
{
	if (shape != nullptr)
		_window->Draw(shape);
}
sf::FloatRect Engine::UI::Shape::Circle::CircleShape::GetGlobalBounds()
{
	return shape->getGlobalBounds();
}
#pragma endregion
