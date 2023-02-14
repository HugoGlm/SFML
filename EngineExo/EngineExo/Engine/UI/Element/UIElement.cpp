#include "UIElement.h"
#include "../../Manager/FontManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../PrimaryType/String/String.h"
#include "../../Utils/Template/Template.h"
#include "../../Utils/DebugMacro.h"

#pragma region constructor
Engine::UI::UIElement::UIElement()
{
	Manager::EventSystem::Instance()->Register(this);
}
Engine::UI::UIElement::UIElement(const char* _label) : super()
{
	labelText.setString(_label);
	labelText.setCharacterSize(12);
	labelText.setFont(*Manager::FontManager::Instance()->GetFont("Arial"));
	Manager::EventSystem::Instance()->Register(this);
}
Engine::UI::UIElement::UIElement(const UIElement& _copy) : super(_copy)
{
	shape = _copy.shape;
	labelText = _copy.labelText;
	canInteract = _copy.canInteract;
	isActive = _copy.isActive;
	Manager::EventSystem::Instance()->Register(this);
}
Engine::UI::UIElement::~UIElement()
{
	delete shape;
	shape = nullptr;
	Manager::EventSystem::Instance()->UnRegister(this);
}
#pragma endregion

#pragma region methods
void Engine::UI::UIElement::SetPosition(const PrimaryType::Vector2& _position)
{
	check((shape != nullptr), "shape is nullptr")
	shape->setPosition(_position);
}
void Engine::UI::UIElement::SetRotation(float _angle)
{
	check((shape != nullptr), "shape is nullptr")
	shape->setRotation(_angle);
}
void Engine::UI::UIElement::SetOrigin(const PrimaryType::Vector2& _origin)
{
	check((shape != nullptr), "shape is nullptr")
		shape->setOrigin(_origin);
}
void Engine::UI::UIElement::SetScale(const PrimaryType::Vector2& _scale)
{
	check((shape != nullptr), "shape is nullptr")
		shape->setScale(_scale);
}
void Engine::UI::UIElement::SetIsActive(bool _status)
{
	isActive = _status;
}
void Engine::UI::UIElement::SetCanInteract(bool _status)
{
	canInteract = _status;
}
void Engine::UI::UIElement::SetLabel(const char* _label)
{
	labelText.setString(_label);
}
bool Engine::UI::UIElement::CanInteract() const
{
	return canInteract;
}
bool Engine::UI::UIElement::IsActive() const
{
	return isActive;
}
sf::Shape* Engine::UI::UIElement::Shape() const
{
	return shape;
}
Engine::PrimaryType::Vector2 Engine::UI::UIElement::Position() const
{
	check((shape != nullptr), "shape is nullptr", PrimaryType::Vector2(0, 0))
	return shape->getPosition();
}
float Engine::UI::UIElement::Rotation() const
{
	check((shape != nullptr), "shape is nullptr", PrimaryType::Float::NaN)
	return shape->getRotation();
}
Engine::PrimaryType::Vector2 Engine::UI::UIElement::Scale() const
{
	check((shape != nullptr), "shape is nullptr", PrimaryType::Vector2(0, 0))
	return shape->getScale();
}
Engine::PrimaryType::Vector2 Engine::UI::UIElement::Origin() const
{
	check((shape != nullptr), "shape is nullptr", PrimaryType::Vector2(0, 0))
	return shape->getOrigin();
}
Engine::PrimaryType::String Engine::UI::UIElement::Label() const
{
	return labelText.getString().toAnsiString().c_str();
}
void Engine::UI::UIElement::Draw(sf::RenderWindow* _window)
{
	checkLow((shape != nullptr), "shape is nullptr for draw")
	_window->draw(labelText);
	_window->draw(*shape);
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::UI::UIElement::operator=(const Object* _obj)
{
	if (!IsSame<UIElement>(_obj))
		return *this;
	super::operator=(_obj);
	const UIElement* _other = dynamic_cast<const UIElement*>(_obj);
	shape = _other->shape;
	labelText = _other->labelText;
	canInteract = _other->canInteract;
	isActive = _other->isActive;
	return *this;
}
#pragma endregion
