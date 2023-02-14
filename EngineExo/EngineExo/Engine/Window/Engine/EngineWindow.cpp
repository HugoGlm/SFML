#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../UI/Toggle/Toggle.h"
#include "../../Time/Time.h"
#include "../../Utils/CoreDefine.h"
#include "../../UI/Button/Button.h"
#include "../../PrimaryType/Vector2/Vector2.h"

#pragma region constructor
Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
	
}
Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
	: super(_copy.name, _copy.width, _copy.height) { }
#pragma endregion

#pragma region override
void Engine::Window::EngineWindow::Test()
{
	LOG("Button Click !")
}
void Engine::Window::EngineWindow::Open()
{
	UI::Button* button = new UI::Button("play", 200, 40);
	button->AddListener<EngineWindow>(this, &EngineWindow::Test);
	button->SetPosition(PrimaryType::Vector2(100, 50));
	UI::Toggle toggle = UI::Toggle(false);
	toggle.SetPosition(PrimaryType::Vector2(100, 150));
	super::Open();
}
void Engine::Window::EngineWindow::OnUpdate()
{
	Time::deltaTime = clock.restart().asSeconds();
	Manager::GameObjectManager::Instance()->Update();
	Manager::EventSystem::Instance()->Update(currentEvent, renderer);
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
}
#pragma endregion