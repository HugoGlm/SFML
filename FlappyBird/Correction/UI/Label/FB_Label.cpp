#include "FB_Label.h"
#include "../../Window/Window.h"

#pragma region constructor
FB_Label::FB_Label(Window* _owner, const char* _text) : FB_UIElement(_owner)
{
	text = new sf::Text();
	text->setString(_text);
	font = new sf::Font();
	if (!font->loadFromFile("C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/aAbsoluteEmpire.ttf"))
	{
		Free();
		return;
	}
	text->setFont(*font);
}
FB_Label::FB_Label(const FB_Label& _copy) : FB_UIElement(_copy)
{
	text = _copy.text;
	font = _copy.font;
}
void FB_Label::Free()
{
	delete text;
	delete font;
	text = nullptr;
	font = nullptr;
}
#pragma endregion

#pragma region methods
FB_Label::~FB_Label()
{
	Free();
}
void FB_Label::SetCharacterSize(const int _size)
{
	text->setCharacterSize(_size);
}
void FB_Label::SetColor(const sf::Color _color)
{
	text->setFillColor(_color);
}
void FB_Label::SetText(const char* _text)
{
	text->setString(_text);
}
#pragma endregion

#pragma region override
void FB_Label::SetPosition(const sf::Vector2f& _position)
{
	text->setPosition(_position);
}
void FB_Label::SetScale(const sf::Vector2f& _scale)
{
	text->setScale(_scale);
}
void FB_Label::Draw(Window* _window)
{
	if (text != nullptr)
		_window->Draw(text);
}
void FB_Label::SetOrigin(const sf::Vector2f& _origin)
{
	text->setOrigin(_origin);
}
sf::FloatRect FB_Label::GetGlobalBounds()
{
	return text->getGlobalBounds();
}
#pragma endregion

