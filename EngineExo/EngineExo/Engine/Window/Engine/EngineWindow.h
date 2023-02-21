#pragma once
#include "../Window.h"
#include "../../UI/Slider/Slider.h"
#include "../../UI/Label/Label.h"
#include "../../UI/Toggle/Toggle.h"
#include "../../UI/Button/Button.h"
#include "../../UI/TextField/TextField.h"

namespace Engine::Window
{
	class EngineWindow : public Window<EngineWindow>
	{
		DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
	private:
		sf::Clock clock = sf::Clock();
		UI::Button* buttonTest = nullptr;
		UI::Button* buttonBack = nullptr;
		UI::Slider* slider = nullptr;
		UI::Toggle* toggle = nullptr;
		UI::TextField* textField = nullptr;
		UI::Label* percentage = new UI::Label();
		UI::Label* boolean = new UI::Label();
		UI::Label* text = new UI::Label();
		bool isActive = false;
#pragma region constructor
	public:
		EngineWindow();
#pragma endregion
#pragma region methods
	private:
		void InitInspectorBox();
		void InitAssetBox();
#pragma endregion
#pragma region override
	public:
		void Test();
		void Back();
		void Open() override;
		void OnUpdate() override;
		void OnClear() const override;
		void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion

	};
}

