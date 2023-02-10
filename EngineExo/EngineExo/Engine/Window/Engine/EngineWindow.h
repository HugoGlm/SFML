#pragma once
#include "../Window.h"
#include "../../UI/Shape/Rectangle/RectangleShape.h"
#include "../../UI/Label/Label.h"

namespace Engine::Window
{
	class EngineWindow : public Window<EngineWindow>
	{
		DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
	private:
		sf::Clock clock = sf::Clock();
		UI::Shape::Rectangle::RectangleShape* button = nullptr;
		UI::Label::Label* cross = nullptr;
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

