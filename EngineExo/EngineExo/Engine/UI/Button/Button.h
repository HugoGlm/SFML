#pragma once
#include "../Element/UIElement.h"
#include "../Interface/IPointerClickHandler.h"
#include "../Interface/IPointerEnterHandler.h"
#include "../Interface/IPointerExitHandler.h"
#include "../../Event/Action/Action.h"

namespace Engine::UI
{
	class Button : public UIElement, public IPointerClickHandler, public IPointerEnterHandler, public IPointerExitHandler
	{
		DECLARE_CLASS_INFO(Button, UIElement)
#pragma region f/p
	private:
		float width = 100.0f;
		float height = 40.0f;
		sf::Text text = sf::Text();
		sf::Color baseColor = sf::Color::White;
		sf::Color enterColor = sf::Color(189, 195, 199);
		Action<> onClick = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Button() = default;
		Button(const std::string& _text, float _width, float _height);
		Button(const std::string& _text, float _width, float _height, Action<> _onClick);
#pragma endregion
#pragma region methods
	public:
		template<typename Class>
		void AddListener(Class* _instance, void(Class::* ptr)())
		{
			onClick.AddDynamic(_instance, ptr);
		}
		template<typename Class>
		void RemoveListener(Class* _instance, void(Class::* ptr)())
		{
			onClick.RemoveDynamic(_instance, ptr);
		}
		void SetBackgroundColor(const sf::Color& _color);
#pragma endregion
#pragma region override
	public:
		void SetPosition(const PrimaryType::Vector2& _position) override;
		void Draw(sf::RenderWindow* _window);
		virtual void OnPointerClick(const sf::Event& _event) override;
		virtual void OnPointerEnter() override;
		virtual void OnPointerExit() override;
#pragma endregion


	};
}
