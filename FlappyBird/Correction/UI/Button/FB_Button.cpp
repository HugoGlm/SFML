#include "FB_Button.h"
#include "../image/FB_Image.h"
#include "../../Window/Window.h"

#pragma region constructor
FB_Button::FB_Button(Window* _owner, const char* _path) : FB_UIElement(_owner)
{
	image = new FB_Image(_owner, _path);
}
FB_Button::FB_Button(const FB_Button& _copy) : FB_UIElement(_copy)
{
	image = _copy.image;
}
FB_Button::~FB_Button()
{
	delete image;
	image = nullptr;
	OnClick = nullptr;
}
#pragma endregion

#pragma region override
void FB_Button::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position);
}
void FB_Button::SetScale(const sf::Vector2f& _scale)
{
	image->SetScale(_scale);
}
void FB_Button::Draw(Window* _window)
{
	image->Draw(_window);
}
void FB_Button::SetOrigin(const sf::Vector2f& _origin)
{
	image->SetOrigin(_origin);
}
void FB_Button::OnUpdate()
{
	if (!isActive)
		return;
	const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && image->GlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
	{
		OnClick.Invoke();
	}
}
sf::FloatRect FB_Button::GetGlobalBounds()
{
	return image->GetGlobalBounds();
}
#pragma endregion

