#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Engine
{
	namespace Window
	{
		class EngineWindow;
	}
	class UIElement : public Object
	{
		//DECLARE_CLASS_INFO(UIElement, Object)
#pragma region f/p
	protected:
		Window::EngineWindow* owner = nullptr;
		bool isInteractable = false;
#pragma endregion
#pragma region constructor
	public:
		UIElement(Window::EngineWindow* _owner);
		UIElement(const UIElement& _copy);
		~UIElement() override;
#pragma endregion
#pragma region methods
	public:
		virtual void SetPosition(const sf::Vector2f& _position) = 0;
		virtual void SetScale(const sf::Vector2f& _scale) = 0;
		virtual void SetOrigin(const sf::Vector2f& _origin) = 0;
		virtual void Draw(Window::EngineWindow* _window) = 0;
		virtual void OnUpdate();
		void SetActive(const bool _status);
		virtual sf::FloatRect GetGlobalBounds() = 0;
#pragma endregion

	};
}
