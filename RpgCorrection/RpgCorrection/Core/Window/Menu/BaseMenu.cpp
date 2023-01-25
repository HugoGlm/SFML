#include "BaseMenu.h"
#include "../Window.h"
#include "../../Utils/Debug/Debug.h"
#include "../../UI/UIElement.h"
#include "../../UI/Button/Button.h"
#include "../../UI/Label/Label.h"
#include "../../UI/Image/Image.h"
#include <format>

#pragma region constructor
Core::BaseMenu::BaseMenu(Window* _owner)
{
	owner = _owner;
}
Core::BaseMenu::BaseMenu(const BaseMenu& _copy)
{
	elements = _copy.elements;
	owner = _copy.owner;
	isOpen = _copy.isOpen;
}
Core::BaseMenu::~BaseMenu()
{
	for (UI::UIElement*& element : elements)
	{
		delete element;
		element = nullptr;
	}
	elements.clear();
}
#pragma endregion

#pragma region methods
void Core::BaseMenu::SetActive(bool _status)
{
	for (UI::UIElement* element : elements)
		element->SetActive(_status);
}
void Core::BaseMenu::Open()
{
	isOpen = true;
	SetActive(true);
}
void Core::BaseMenu::Close()
{
	isOpen = false;
	SetActive(false);
}
void Core::BaseMenu::Draw()
{
	if (!isOpen)
		return;
	for (UI::UIElement* _element : elements)
		_element->Draw();
}
void Core::BaseMenu::OnUpdate()
{
	if (!isOpen)
		return;
	for (UI::UIElement* _element : elements)
		_element->OnUpdate();
}
bool Core::BaseMenu::IsOpen() const
{
	return isOpen;
}
void Core::BaseMenu::OnResize(const sf::Vector2f& _size) { }

Core::UI::Image* Core::BaseMenu::CreateImage(const sf::Vector2f& _position, const char* _texture)
{
	UI::Image* _image = new UI::Image(owner, _texture);
	check((_image != nullptr && _image->IsValid()), std::format("[BaseMenu] => failure to create the image with {} texture", _texture), nullptr)
		_image->SetPosition(_position);
	elements.push_back(_image);
	return _image;
}
Core::UI::Button* Core::BaseMenu::CreateButton(const sf::Vector2f& _position, const char* _texture, const Event::Delegate<void>& _onClick)
{
	UI::Button* _button = new UI::Button(owner, _texture);
	check((_button != nullptr && _button->IsValid()), std::format("[BaseMenu] => failure to create the button with {} texture", _texture), nullptr)
	_button->OnClick = _onClick;
	_button->SetPosition(_position);
	elements.push_back(_button);
	return _button;
}
Core::UI::Label* Core::BaseMenu::CreateLabel(const sf::Vector2f& _position, const char* _text)
{
	UI::Label* _label = new UI::Label(owner, _text);
	check((_label != nullptr && _label->IsValid()), "[BaseMenu] => failure to create the label with {} texture", nullptr)
	_label->SetPosition(_position);
	elements.push_back(_label);
	return _label;
}
#pragma endregion

