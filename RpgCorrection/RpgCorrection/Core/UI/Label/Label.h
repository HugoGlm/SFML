#pragma once
#include "../UIElement.h"

namespace Core
{
	namespace UI
	{
		class Label : public UIElement
		{
			DECLARE_CLASS_INFO(Label, UIElement)
#pragma region f/p
		protected:
			sf::Text* text = nullptr;
#pragma endregion
#pragma region constructor
		public:
			Label() = delete;
			Label(Window* _owner, const char* _text);
			Label(const Label& _copy);
#pragma endregion
#pragma region methods
		public:
			void SetText(const char* _text) const;
			void SetFont(const sf::Font* _font) const;
			void SetCharacterSize(int _size) const;
#pragma endregion
#pragma region override
			public:
				virtual void SetPosition(const sf::Vector2f& _position) override;
				virtual sf::Vector2f Position() const override;
				virtual void SetOrigin(const sf::Vector2f& _origin) override;
				virtual sf::Vector2f Origin() const override;
				virtual void SetScale(const sf::Vector2f& _scale) override;
				virtual sf::Vector2f Scale() const override;
				virtual sf::FloatRect GlobalBounds() const override;
#pragma endregion
		};
	}
}

