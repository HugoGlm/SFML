#include "FB_Image.h"
#include "../../Window/Window.h"

#pragma region constructor
FB_Image::FB_Image(Window* _owner, const char* _path) : FB_UIElement(_owner)
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (!texture->loadFromFile(_path))
	{
		Free();
		return;
	}
	sprite->setTexture(*texture);
}
FB_Image::FB_Image(const FB_Image& _copy) : FB_UIElement(_copy)
{
	sprite = _copy.sprite;
	texture = _copy.texture;
}
FB_Image::~FB_Image()
{
	Free();
}
#pragma endregion

#pragma region methods
void FB_Image::Free()
{
	delete sprite;
	delete texture;
	sprite = nullptr;
	texture = nullptr;
}
sf::FloatRect FB_Image::GlobalBounds() const
{
	return sprite->getGlobalBounds();
}
#pragma endregion

#pragma region override
void FB_Image::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);
}
void FB_Image::SetScale(const sf::Vector2f& _scale)
{
	sprite->setScale(_scale);
}
void FB_Image::Draw(Window* _window)
{
	if (sprite != nullptr)
		_window->Draw(sprite);
}
void FB_Image::SetOrigin(const sf::Vector2f& _origin)
{
	sprite->setOrigin(_origin);
}
sf::FloatRect FB_Image::GetGlobalBounds()
{
	return sprite->getGlobalBounds();
}
#pragma endregion

