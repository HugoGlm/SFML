#pragma once
#include "../../UIElement.h"
#include "../../../Event/Delegate/Delegate.h"

namespace Engine
{
	namespace Window
	{
		class EngineWindow;
	}
	namespace UI::Shape::Rectangle
	{
		class RectangleShape : public UIElement
		{
			DECLARE_CLASS_INFO(RectangleShape, UIElement)
#pragma region f/p
		private:
			sf::RectangleShape* shape = nullptr;
		public:
			Event::Delegate<void> OnClick = nullptr;
#pragma endregion
#pragma region constructor
		public:
			RectangleShape(Window::EngineWindow* _owner, sf::Vector2f _size, sf::Vector2f _position);
			virtual ~RectangleShape() override;
#pragma endregion
#pragma region override
		public:
			virtual void SetPosition(const sf::Vector2f& _position) override;
			virtual void SetScale(const sf::Vector2f& _scale) override;
			virtual void SetOrigin(const sf::Vector2f& _origin) override;
			virtual void Draw(Window::EngineWindow* _window) const override;
			virtual sf::FloatRect GetGlobalBounds() override;
#pragma endregion

		};
	}
}

