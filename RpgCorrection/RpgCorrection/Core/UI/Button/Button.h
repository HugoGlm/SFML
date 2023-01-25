#pragma once
#include "../UIElement.h"
#include "../../Event/Delegate/Delegate.h"

namespace Core
{
	namespace UI
	{
		class Button :public UIElement
		{
			DECLARE_CLASS_INFO(Button, UIElement)
#pragma region f/p
		private:
			class Image* image = nullptr;
		public:
			Event::Delegate<void> OnClick = nullptr;
#pragma endregion
#pragma region constructor
		public:
			Button() = delete;
			Button(Window* _owner, const char* _path);
			Button(const Button& _copy);
			~Button() override;
#pragma endregion
#pragma region override
		public:
			virtual bool IsValid() const override;
			virtual void SetActive(bool _status) override;
			virtual void Draw() override;
			virtual void OnUpdate() override;
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

