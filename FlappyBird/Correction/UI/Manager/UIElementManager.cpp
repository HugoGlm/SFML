#include "UIElementManager.h"
#include "../FB_UIElement.h"

#pragma region methods
void UIElementManager::Register(FB_UIElement* _element)
{
	elements.push_back(_element);
}
void UIElementManager::UnRegister(FB_UIElement* _element)
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (elements[i] == _element)
		{
			elements.erase(elements.begin() + 1);
			break;
		}
	}
}
void UIElementManager::Update()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
	{
		elements[i]->OnUpdate();
	}
}
#pragma endregion

#pragma region override
void UIElementManager::OnDestroy()
{
	const size_t _size = elements.size();
	for (size_t i = 0; i < _size; i++)
		delete elements[i];
	elements.clear();
}
#pragma endregion

