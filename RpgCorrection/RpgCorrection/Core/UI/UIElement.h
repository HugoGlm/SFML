#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Core
{
	class Window;
	namespace UI
	{
		class UIElement : public Object
		{
			DECLARE_CLASS_INFO(UIElement, Object)
#pragma region f/p
		protected:
			bool isActive = false;
			sf::Drawable* drawable = nullptr;
			Window* owner = nullptr;
#pragma endregion
#pragma region constructor
		public:
			UIElement() = delete;
			UIElement(Window* _owner);
			UIElement(const UIElement& _copy);
			~UIElement() override;
#pragma endregion
#pragma region methods
		public:
			virtual void SetActive(bool _status);
			bool IsActive() const;
			virtual bool IsValid() const;
			virtual void Draw();
			virtual void OnUpdate();
			virtual void SetPosition(const sf::Vector2f& _position) = 0;
			virtual sf::Vector2f Position() const = 0;
			virtual void SetOrigin(const sf::Vector2f& _origin) = 0;
			virtual sf::Vector2f Origin() const = 0;
			virtual void SetScale(const sf::Vector2f& _scale) = 0;
			virtual sf::Vector2f Scale() const = 0;
			virtual sf::FloatRect GlobalBounds() const = 0;
#pragma endregion

		};
	}
}

