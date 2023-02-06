#include "Selection.h"

#pragma region methods
void Engine::Selection::SetSelection(Object* _obj)
{
	if (selected == _obj)
		return;
	selected = _obj;
	OnSelectionChanged.Invoke(selected);
}
Engine::Object* Engine::Selection::GetSelected()
{
	return selected;
}
#pragma endregion

