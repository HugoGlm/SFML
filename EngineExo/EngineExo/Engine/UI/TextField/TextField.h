#pragma once
#include "../Element/UIElement.h"
#include "../Interface/IPointerClickHandler.h"
#include "../Interface/IPointerEnterHandler.h"
#include "../Interface/IPointerExitHandler.h"
#include "../Interface/ITextEntered.h"

namespace Engine::UI
{
	class TextField : public UIElement, public IPointerClickHandler, public IPointerEnterHandler,
		public IPointerExitHandler, public ITextEntered
	{
		DECLARE_CLASS_INFO(TextField, UIElement)
#pragma region f/p
	private:
		std::string inputText = std::string();
		std::string inputDefaultText = std::string();
		bool isSelected = false;
		sf::Text text = sf::Text();
#pragma endregion
#pragma region constructor
	public:
		TextField();
		TextField(const char* _label, const char* _defaultText, const PrimaryType::Vector2& _size);
		TextField(const char* _defaultText, const PrimaryType::Vector2& _size);
#pragma endregion
#pragma region methods
	public:
		void SetText(const char* _text);
#pragma endregion
#pragma region override
	public:
		void Draw(sf::RenderWindow* _window) override;
		void SetPosition(const PrimaryType::Vector2& _position) override;
		void OnPointerEnter() override;
		void OnPointerExit() override; 
		void OnPointerClick(const sf::Event& _event) override;
		void OnPointerUnClick() override;
		void OnTextEntered(sf::Uint32 _unicode) override;
#pragma endregion
	};
}
