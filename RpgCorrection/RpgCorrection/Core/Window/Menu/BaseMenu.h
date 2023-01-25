#pragma once
#include "../../Object/Object.h"
#include "../../Event/Delegate/Delegate.h"
#include <vector>
#include <SFML/Graphics.hpp>

namespace Core
{
	namespace UI
	{
		class UIElement;
		class Image;
		class Label;
		class Button;
	}
	class BaseMenu : public Object
	{
		DECLARE_CLASS_INFO(BaseMenu, Object)
#pragma region f/p
	protected:
		std::vector<UI::UIElement*> elements = std::vector<UI::UIElement*>();
		class Window* owner = nullptr;
		bool isOpen = false;
#pragma endregion
#pragma region constructor
	public:
		BaseMenu() = delete;
		BaseMenu(Window* _owner);
		BaseMenu(const BaseMenu& _copy);
		~BaseMenu() override;
#pragma endregion
#pragma region methods
	private:
		virtual void SetActive(bool _status);
	public:
		virtual void Open();
		virtual void Close();
		virtual void Draw();
		virtual void OnUpdate();
		bool IsOpen() const;
		virtual void OnResize(const sf::Vector2f& _size);
	protected:
		UI::Image* CreateImage(const sf::Vector2f& _position, const char* _texture);
		UI::Button* CreateButton(const sf::Vector2f& _position, const char* _texture, const Event::Delegate<void>& _onClick);
		UI::Label* CreateLabel(const sf::Vector2f& _position, const char* _text);
#pragma endregion

	};
}

