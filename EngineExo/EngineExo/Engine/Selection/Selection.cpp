#include "Selection.h"

#pragma region constructor
Engine::Selection::Selection(const Selection& _copy) = default;
#pragma endregion

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

