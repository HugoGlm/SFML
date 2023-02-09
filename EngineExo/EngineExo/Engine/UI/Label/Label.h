#pragma once
#include "../UIElement.h"

namespace Engine::Window
{
	class EngineWindow;
}
namespace Engine::Label
{
	class Label : public UIElement
	{
		DECLARE_CLASS_INFO(Label, UIElement)
#pragma region f/p
	private:
		sf::Text* text = nullptr;
		sf::Font* font = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Label(Window::EngineWindow* _owner, const char* _text, const char* _font);
		~Label() override;
#pragma endregion
#pragma region methods
	public:
		void Free();
		void SetCharacterSize(const int _size);
		void SetColor(const sf::Color _color);
		void SetText(const char* _text);
#pragma endregion
#pragma region override
	public:
		virtual void SetPosition(const sf::Vector2f& _position) override;
		virtual void SetScale(const sf::Vector2f& _scale) override;
		virtual void SetOrigin(const sf::Vector2f& _origin) override;
		virtual void Draw(Window::EngineWindow* _window) override;
		virtual sf::FloatRect GetGlobalBounds() override;
#pragma endregion

	};
}
