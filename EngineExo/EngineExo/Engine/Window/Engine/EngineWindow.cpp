#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Time/Time.h"
#include "../../Utils/CoreDefine.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../Editor/Window/EditorWindow.h"
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
void Engine::Window::EngineWindow::RegisterEditorWindow(Editor::EditorWindow* _window)
{
	editorWindows.push_back(_window);
}
void Engine::Window::EngineWindow::UnRegisterEditorWindow(Editor::EditorWindow* _window)
{
	std::erase(editorWindows, _window);
}
#pragma endregion

#pragma region override
void Engine::Window::EngineWindow::Open()
{
	super::Open();
}
void Engine::Window::EngineWindow::OnUpdate()
{
	Time::deltaTime = clock.restart().asSeconds();
	Manager::GameObjectManager::Instance()->Update();
	Clear();
	Manager::GameObjectManager::Instance()->Draw(this);
	for (Editor::EditorWindow* _editorWindow : editorWindows)
		_editorWindow->Draw(renderer);
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