#include "Button.h"
#include "../Image/Image.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region constructor
Engine::UI::Button::Button::Button(Window::EngineWindow* _owner, const char* _path) : UIElement(_owner)
{
	image = new UI::Image::Image(_owner, _path);
}
Engine::UI::Button::Button::Button(const Button& _copy) : UIElement(_copy)
{
	image = _copy.image;
}
Engine::UI::Button::Button::~Button()
{
	delete image;
	image = nullptr;
	OnClick = nullptr;
}
#pragma endregion

#pragma region override
void Engine::UI::Button::Button::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position);
}
void Engine::UI::Button::Button::SetScale(const sf::Vector2f& _scale)
{
	image->SetScale(_scale);
}
void Engine::UI::Button::Button::SetOrigin(const sf::Vector2f& _origin)
{
	image->SetOrigin(_origin);
}
void Engine::UI::Button::Button::Draw(Window::EngineWindow* _window) const
{
	image->Draw(_window);
}
sf::FloatRect Engine::UI::Button::Button::GetGlobalBounds()
{
	return image->GetGlobalBounds();
}
#pragma endregion
