#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Time/Time.h"
#include "../../Utils/CoreDefine.h"
#include "../../UI/Button/Button.h"

#include "../../UI/TextField/TextField.h"

#include "../../PrimaryType/Vector2/Vector2.h"
#include <format>
#include <iostream>

#pragma region constructor
Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{

}
Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
	: super(_copy.name, _copy.width, _copy.height) { }
#pragma endregion

#pragma region methods
void Engine::Window::EngineWindow::InitInspectorBox()
{
	UI::UIElement* _inspectorBox = new UI::UIElement();
	_inspectorBox->SetShape(new sf::RectangleShape(sf::Vector2f(250, 825)));
	_inspectorBox->SetPosition(PrimaryType::Vector2(1670, 0));
	_inspectorBox->SetOutlineThickness(5.f);
	_inspectorBox->SetOutlineColor(sf::Color(211, 211, 211));
	_inspectorBox->SetColor(sf::Color::Transparent);

	UI::Label* _inspectorText = new UI::Label("Inspector");
	_inspectorText->SetPosition(PrimaryType::Vector2(1760, 10));
}
void Engine::Window::EngineWindow::InitAssetBox()
{
	UI::UIElement* _assetBox = new UI::UIElement();
	_assetBox->SetShape(new sf::RectangleShape(sf::Vector2f(1920, 250)));
	_assetBox->SetPosition(PrimaryType::Vector2(0, 830));
	_assetBox->SetOutlineThickness(5.f);
	_assetBox->SetOutlineColor(sf::Color(211, 211, 211));
	_assetBox->SetColor(sf::Color::Transparent);

	UI::Button* _buttonTest = new UI::Button("Test", 50, 50);
	_buttonTest->AddListener<EngineWindow>(this, &EngineWindow::Test);
	_buttonTest->SetPosition(PrimaryType::Vector2(50, 900));

	UI::Label* _assetText = new UI::Label("Asset");
	_assetText->SetPosition(PrimaryType::Vector2(10, 800));
}
#pragma endregion

#pragma region override
void Engine::Window::EngineWindow::Test()
{
	isActive = true;
	slider = new UI::Slider();
	slider->SetPosition(PrimaryType::Vector2(1700, 100));
	slider->SetValue(50);

	UI::TextField* textField = new UI::TextField();
	textField->SetPosition(PrimaryType::Vector2(1700, 200));

	toggle->SetPosition(PrimaryType::Vector2(1700, 300));
}
void Engine::Window::EngineWindow::Open()
{
	InitAssetBox();
	InitInspectorBox();
	super::Open();
}
void Engine::Window::EngineWindow::OnUpdate()
{
	if (isActive == true)
	{
		pourcentage->SetLabel(std::to_string(slider->Value()).c_str());
		pourcentage->SetPosition(PrimaryType::Vector2(1850, 95));
		pourcentage->SetLabel(std::to_string(toggle->Status()).c_str());
		pourcentage->SetPosition(PrimaryType::Vector2(1800, 300));
	}

	Time::deltaTime = clock.restart().asSeconds();
	Manager::GameObjectManager::Instance()->Update();
	Clear();
	Manager::GameObjectManager::Instance()->Draw(this);
	Manager::EventSystem::Instance()->Draw(renderer);
	Display();
}
void Engine::Window::EngineWindow::OnClear() const
{
	super::OnClear();
}
void Engine::Window::EngineWindow::OnReceiveEvent(const sf::Event& _event)
{
	super::OnReceiveEvent(_event);
	Manager::EventSystem::Instance()->Update(currentEvent, renderer);
}
#pragma endregion