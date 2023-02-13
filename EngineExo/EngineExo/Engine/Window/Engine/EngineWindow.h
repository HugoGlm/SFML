#pragma once
#include "../Window.h"
#include "../../UI/Shape/Rectangle/RectangleShape.h"
#include "../../UI/Shape/Circle/CircleShape.h"
#include "../../UI/Label/Label.h"

namespace Engine::Window
{
	class EngineWindow : public Window<EngineWindow>
	{
		DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
	private:
		sf::Clock clock = sf::Clock();
		bool checked = false;
		UI::Shape::Rectangle::RectangleShape* button = nullptr;
		UI::Shape::Rectangle::RectangleShape* line = nullptr;
		UI::Shape::Rectangle::RectangleShape* text = nullptr;
		UI::Shape::Circle::CircleShape* circleLine = nullptr;
		UI::Label::Label* cross = nullptr;
		UI::Label::Label* pourcentage = nullptr;
#pragma region constructor
	public:
		EngineWindow();
#pragma endregion
#pragma region override
	public:
		void Open() override;
		void OnUpdate() override;
		void OnClear() const override;
		void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion

	};
}

