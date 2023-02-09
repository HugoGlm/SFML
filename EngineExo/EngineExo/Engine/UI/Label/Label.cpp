#include "Label.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region constructor
Engine::Label::Label::Label(Window::EngineWindow* _owner, const char* _text, const char* _font) : UIElement(_owner)
{
	text = new sf::Text();
	text->setString(_text);
	font = new sf::Font();
	if (!font->loadFromFile(_font))
	{
		Free();
		return;
	}
	text->setFont(*font);
}
Engine::Label::Label::Label(const Label& _copy) : UIElement(_copy)
{
	text = _copy.text;
	font = _copy.font;
}
Engine::Label::Label::~Label()
{
	Free();
}
#pragma endregion

#pragma region methods
void Engine::Label::Label::Free()
{
	delete text;
	delete font;
	text = nullptr;
	font = nullptr;
}
void Engine::Label::Label::SetCharacterSize(const int _size)
{
	text->setCharacterSize(_size);
}
void Engine::Label::Label::SetColor(const sf::Color _color)
{
	text->setColor(_color);
}
void Engine::Label::Label::SetText(const char* _text)
{
	text->setString(_text);
}
#pragma endregion

#pragma region override
void Engine::Label::Label::SetPosition(const sf::Vector2f& _position)
{
	text->setPosition(_position);
}
void Engine::Label::Label::SetScale(const sf::Vector2f& _scale)
{
	text->setScale(_scale);
}
void Engine::Label::Label::SetOrigin(const sf::Vector2f& _origin)
{
	text->setOrigin(_origin);
}
void Engine::Label::Label::Draw(Window::EngineWindow* _window)
{
	if (text != nullptr)
		_window->Draw(text);
}
sf::FloatRect Engine::Label::Label::GetGlobalBounds()
{
	return text->getGlobalBounds();
}
#pragma endregion
