#pragma once
#include "../Window.h"

namespace Engine::Editor
{
	class EditorWindow;
}

namespace Engine::Window
{
	class EngineWindow : public Window<EngineWindow>
	{
		DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
	private:
		std::vector<Editor::EditorWindow*> editorWindows = std::vector<Editor::EditorWindow*>();
		sf::Clock clock = sf::Clock();
#pragma region constructor
	public:
		EngineWindow();
#pragma endregion
#pragma region methods
	public:
		void RegisterEditorWindow(Editor::EditorWindow* _window);
		void UnRegisterEditorWindow(Editor::EditorWindow* _window);
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

