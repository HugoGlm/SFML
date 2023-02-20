#pragma once
#include "../Window.h"
#include "../../UI/Slider/Slider.h"
#include "../../UI/Label/Label.h"
#include "../../UI/Toggle/Toggle.h"

namespace Engine::Window
{
	class EngineWindow : public Window<EngineWindow>
	{
		DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
	private:
		sf::Clock clock = sf::Clock();
		UI::Slider* slider = nullptr;
		UI::Label* pourcentage = new UI::Label();
		UI::Toggle* toggle = new UI::Toggle(true);
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
		void Open() override;
		void OnUpdate() override;
		void OnClear() const override;
		void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion

	};
}

