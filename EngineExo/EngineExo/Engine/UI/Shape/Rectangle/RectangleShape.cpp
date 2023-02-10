#include "RectangleShape.h"
#include "../../../Window/Engine/EngineWindow.h"

#pragma region constructor
Engine::UI::Shape::Rectangle::RectangleShape::RectangleShape(Window::EngineWindow* _owner, sf::Vector2f _size, sf::Vector2f _position) : UIElement(_owner)
{
	shape = new sf::RectangleShape(_size);
	shape->setPosition(_position);
}
Engine::UI::Shape::Rectangle::RectangleShape::RectangleShape(const RectangleShape& _copy) : UIElement(_copy)
{
	shape = _copy.shape;
}
Engine::UI::Shape::Rectangle::RectangleShape::~RectangleShape()
{
	delete shape;
	shape = nullptr;
	OnClick = nullptr;
}
#pragma endregion

#pragma region override
void Engine::UI::Shape::Rectangle::RectangleShape::SetPosition(const sf::Vector2f& _position)
{
	shape->setPosition(_position);
}
void Engine::UI::Shape::Rectangle::RectangleShape::SetScale(const sf::Vector2f& _scale)
{
	shape->setScale(_scale);
}
void Engine::UI::Shape::Rectangle::RectangleShape::SetOrigin(const sf::Vector2f& _origin)
{
	shape->setOrigin(_origin);
}
void Engine::UI::Shape::Rectangle::RectangleShape::Draw(Window::EngineWindow* _window) const
{
	if (shape != nullptr)
		_window->Draw(shape);
}
sf::FloatRect Engine::UI::Shape::Rectangle::RectangleShape::GetGlobalBounds()
{
	return shape->getGlobalBounds();
}
#pragma endregion
