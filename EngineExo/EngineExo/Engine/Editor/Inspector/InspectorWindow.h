#pragma once
#include "../Window/EditorWindow.h"

namespace Engine::Editor
{
	class InspectorWindow : public EditorWindow
	{
		DECLARE_CLASS_INFO(InspectorWindow, EditorWindow)
#pragma region constructor
	public:
		InspectorWindow();
		~InspectorWindow();
#pragma endregion
#pragma region methods
	public:
		void OnSelectionchanged(Object* _o);
#pragma endregion

	};
}
