#pragma once
#include "../UIElement.h"
#include "../../Event/Delegate/Delegate.h"

namespace Engine
{
	namespace Window
	{
		class EngineWindow;
	}
	namespace Image
	{
		class Image;
	}
	namespace Button
	{
		class Button : public UIElement
		{
			DECLARE_CLASS_INFO(Button, UIElement)
#pragma region f/p
		private:
			Image::Image* image = nullptr;
		public:
			Event::Delegate<void> OnClick = nullptr;
#pragma endregion
#pragma region constructor
		public:
			Button(Window::EngineWindow* _owner, const char* _path);
			virtual ~Button() override;
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
}
