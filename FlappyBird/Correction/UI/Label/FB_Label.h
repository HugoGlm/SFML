#pragma once
#include "../FB_UIElement.h"

class FB_Label : public FB_UIElement
{
#pragma region f/p
private:
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_Label(Window* _owner, const char* _text);
	FB_Label(const FB_Label& _copy);
	~FB_Label() override;
#pragma endregion
#pragma region methods
	void Free();
	void SetCharacterSize(const int _size);
	void SetColor(const sf::Color _color);
	void SetText(const char* _text);
#pragma endregion
#pragma region override
public:
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
	virtual sf::FloatRect GetGlobalBounds() override;
#pragma endregion
};

