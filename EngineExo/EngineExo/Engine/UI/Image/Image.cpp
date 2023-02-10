#include "Image.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region constructor
Engine::UI::Image::Image::Image(Window::EngineWindow* _owner, const char* _path) : UIElement(_owner)
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
Engine::UI::Image::Image::Image(const Image& _copy) : UIElement(_copy)
{
	sprite = _copy.sprite;
	texture = _copy.texture;
}
Engine::UI::Image::Image::~Image()
{
	Free();
}
#pragma endregion

#pragma region methods
void Engine::UI::Image::Image::Free()
{
	delete sprite;
	delete texture;
	sprite = nullptr;
	texture = nullptr;
}
sf::FloatRect Engine::UI::Image::Image::GlobalBounds() const
{
	return sprite->getGlobalBounds();
}
#pragma endregion

#pragma region override
void Engine::UI::Image::Image::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);
}
void Engine::UI::Image::Image::SetScale(const sf::Vector2f& _scale)
{
	sprite->setScale(_scale);
}
void Engine::UI::Image::Image::SetOrigin(const sf::Vector2f& _origin)
{
	sprite->setOrigin(_origin);
}
void Engine::UI::Image::Image::Draw(Window::EngineWindow* _window) const
{
	if (sprite != nullptr)
		_window->Draw(sprite);
}
sf::FloatRect Engine::UI::Image::Image::GetGlobalBounds()
{
	return sprite->getGlobalBounds();
}
#pragma endregion
