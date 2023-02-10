#include "Label.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region constructor
Engine::UI::Label::Label::Label(Window::EngineWindow* _owner, sf::Vector2f _position, const char* _text) : UIElement(_owner)
{
	text = new sf::Text();
	text->setString(_text);
	font = new sf::Font();
	if (!font->loadFromFile("C:/Users/GUIL2804/source/repos/SFML/EngineExo/Font/aAbsoluteEmpire.ttf"))
	{
		Free();
		return;
	}
	text->setFont(*font);
	text->setPosition(_position);
}
Engine::UI::Label::Label::Label(const Label& _copy) : UIElement(_copy)
{
	text = _copy.text;
	font = _copy.font;
}
Engine::UI::Label::Label::~Label()
{
	Free();
}
#pragma endregion

#pragma region methods
void Engine::UI::Label::Label::Free()
{
	delete text;
	delete font;
	text = nullptr;
	font = nullptr;
}
void Engine::UI::Label::Label::SetCharacterSize(const int _size)
{
	text->setCharacterSize(_size);
}
void Engine::UI::Label::Label::SetColor(const sf::Color _color)
{
	text->setColor(_color);
}
void Engine::UI::Label::Label::SetText(const char* _text)
{
	text->setString(_text);
}
#pragma endregion

#pragma region override
void Engine::UI::Label::Label::SetPosition(const sf::Vector2f& _position)
{
	text->setPosition(_position);
}
void Engine::UI::Label::Label::SetScale(const sf::Vector2f& _scale)
{
	text->setScale(_scale);
}
void Engine::UI::Label::Label::SetOrigin(const sf::Vector2f& _origin)
{
	text->setOrigin(_origin);
}
void Engine::UI::Label::Label::Draw(Window::EngineWindow* _window) const
{
	if (text != nullptr)
		_window->Draw(text);
}
sf::FloatRect Engine::UI::Label::Label::GetGlobalBounds()
{
	return text->getGlobalBounds();
}
#pragma endregion
