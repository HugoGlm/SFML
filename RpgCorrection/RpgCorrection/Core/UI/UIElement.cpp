#include "UIElement.h"
#include "../Utils/Debug/Debug.h"
#include "../Window/Window.h"

#pragma region constructor
Core::UI::UIElement::UIElement(Window* _owner)
{
	owner = _owner;
	//TODO Register to manager
}
Core::UI::UIElement::UIElement(const UIElement& _copy)
{
	owner = _copy.owner;
	drawable = _copy.drawable;
	//TODO Register to manager
}
Core::UI::UIElement::~UIElement()
{
	//TODO UnRegister to manager
	delete drawable;
	drawable = nullptr;
}
#pragma endregion

#pragma region methods
void Core::UI::UIElement::SetActive(bool _status)
{
	isActive = _status;
}
bool Core::UI::UIElement::IsActive() const
{
	return isActive;
}
bool Core::UI::UIElement::IsValid() const
{
	return drawable != nullptr && owner != nullptr;
}
void Core::UI::UIElement::Draw()
{
	if (!isActive)
		return;
	checkLow(IsValid(), "[UIElement] => owner or drawable is not valid !")
	owner->Draw(drawable);
}
void Core::UI::UIElement::OnUpdate() { }
#pragma endregion

