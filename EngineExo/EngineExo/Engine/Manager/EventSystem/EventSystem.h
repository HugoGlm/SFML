#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <SFML/Graphics.hpp>

namespace Engine::UI
{
	class UIElement;
}

class IPointerClickHandler;

namespace Engine::Manager
{
	class EventSystem : public Utils::Singleton<EventSystem>
	{
		DECLARE_CLASS_INFO(EventSystem, Singleton<EventSystem>)
#pragma region f/p
	private:
		std::vector<UI::UIElement*> elements = std::vector<UI::UIElement*>();
		std::vector<UI::UIElement*> hoveredElements = std::vector<UI::UIElement*>();
		IPointerClickHandler* pointerClickHandler = nullptr;
#pragma endregion
#pragma region constructor
	public:
		EventSystem() = default;
#pragma endregion
#pragma region methods
	private:
		void RemoveHoveredElement(const UI::UIElement* _element);
		void CheckExitHandler(Engine::UI::UIElement*& _element);
		void CheckEnterHandler(Engine::UI::UIElement*& _element);
		void CheckPointerClickHandler(Engine::UI::UIElement* _element, const sf::Event& _event);
		void CheckPointerMoveHandler(const sf::Event& _event, Engine::UI::UIElement* _element);
		void CheckTextEntered(const sf::Event& _event, Engine::UI::UIElement* _element);
	public:
		void Register(UI::UIElement* _element);
		void UnRegister(UI::UIElement* _element);
		void Update(const sf::Event& _event, const sf::Window* _window);
		void Draw(sf::RenderWindow* _window);
#pragma endregion
#pragma region override
		void OnDestroy() override;
#pragma endregion

	};
}
