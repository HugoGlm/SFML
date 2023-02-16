#pragma once
#include "../Element/UIElement.h"

namespace Engine::UI
{
	class Label : public UIElement
	{
		DECLARE_CLASS_INFO(Label, UIElement)
#pragma region f/p
	private:
		sf::Text text = sf::Text();
#pragma endregion
#pragma region constructor
	public:
		Label();
		Label(const char* _text, int _characterSize = 12, const char* _fontName = "aAbsoluteEmpire");
#pragma endregion
#pragma region methods
	public:
		void SetFont(const char* _fontName);
		void SetCharacterSize(int _value);
		void SetColor(const sf::Color& _color);
#pragma endregion
#pragma region override
	public:
		void SetPosition(const PrimaryType::Vector2& _position) override;
		void SetRotation(float _angle) override;
		void SetOrigin(const PrimaryType::Vector2& _origin) override;
		void SetScale(const PrimaryType::Vector2& _scale) override;
		void SetLabel(const char* _label) override;
		sf::Shape* Shape() const override;
		PrimaryType::Vector2 Position() const override;
		float Rotation() const override;
		PrimaryType::Vector2 Scale() const override;
		PrimaryType::Vector2 Origin() const override;
		PrimaryType::String LabelText() const override;
		void Draw(sf::RenderWindow* _window) override;
#pragma endregion

	};
}
