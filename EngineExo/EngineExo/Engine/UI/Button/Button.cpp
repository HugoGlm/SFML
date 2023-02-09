#include "Button.h"
#include "../Image/Image.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region constructor
Engine::Button::Button::Button(Window::EngineWindow* _owner, const char* _path) : UIElement(_owner)
{
	image = new Image::Image(_owner, _path);
}
Engine::Button::Button::Button(const Button& _copy) : UIElement(_copy)
{
	image = _copy.image;
}
Engine::Button::Button::~Button()
{
	delete image;
	image = nullptr;
	OnClick = nullptr;
}
#pragma endregion

#pragma region override
void Engine::Button::Button::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position);
}
void Engine::Button::Button::SetScale(const sf::Vector2f& _scale)
{
	image->SetScale(_scale);
}
void Engine::Button::Button::SetOrigin(const sf::Vector2f& _origin)
{
	image->SetOrigin(_origin);
}
void Engine::Button::Button::Draw(Window::EngineWindow* _window)
{
	image->Draw(_window);
}
sf::FloatRect Engine::Button::Button::GetGlobalBounds()
{
	return image->GetGlobalBounds();
}
#pragma endregion
