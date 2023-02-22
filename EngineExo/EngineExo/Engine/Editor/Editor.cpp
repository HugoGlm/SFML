#include "Editor.h"
#include "../Manager/EventSystem/EventSystem.h"
#include "../Reflection/Field/FieldInfo.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/Double/Double.h"
#include "../PrimaryType/List/IList.h"
#include "../UI/Toggle/Toggle.h"

#pragma region constructor
Engine::Editor::Editor::Editor(Object* _object) : super()
{
	currentObjectEdit = _object;
}
Engine::Editor::Editor::Editor(const Editor& _copy) : super(_copy)
{
	currentObjectEdit = _copy.currentObjectEdit;
}
#pragma endregion

#pragma region methods
Engine::Editor::EValueType Engine::Editor::Editor::GetValueType(Object* _object)
{
	if (dynamic_cast<PrimaryType::Integer*>(_object)) return EValueType::Int;
	if (dynamic_cast<PrimaryType::String*>(_object)) return EValueType::String;
	if (dynamic_cast<PrimaryType::Float*>(_object)) return EValueType::Float;
	if (dynamic_cast<PrimaryType::Double*>(_object)) return EValueType::Double;
	if (dynamic_cast<PrimaryType::Boolean*>(_object)) return EValueType::Bool;
	if (dynamic_cast<PrimaryType::Vector2*>(_object)) return EValueType::Vector;
	if (dynamic_cast<PrimaryType::IList*>(_object)) return EValueType::List;
	return EValueType::Object;
}
void Engine::Editor::Editor::SetObjectEdit(Object* _object)
{
	for (UI::UIElement* _element : elements)
	{
		Manager::EventSystem::Instance()->UnRegister(_element);
		delete _element;
	}
	elements.clear();
	currentPosition = initialPosition;
	currentObjectEdit = _object;
}
void Engine::Editor::Editor::SetPosition(const PrimaryType::Vector2& _position)
{
	currentPosition = _position;
	initialPosition = _position;
}
void Engine::Editor::Editor::InspectorGUI()
{
	if (currentObjectEdit == nullptr)
		return;
	currentPosition.y += 30;
	std::vector <Reflection::FieldInfo*> _allFields = currentObjectEdit->Fields();
	for (Reflection::FieldInfo* _field : _allFields)
	{
		switch (GetValueType(_field->ReflectedObject()))
		{
		case EValueType::Int: break;
		case EValueType::Bool: 
		{
			PrimaryType::Boolean* _value = dynamic_cast<PrimaryType::Boolean*>(_field->ReflectedObject());
			UI::Toggle* _toggle = new UI::Toggle(*_value);
			_toggle->SetPosition(currentPosition);
			elements.push_back(_toggle);
			currentPosition.y += _toggle->Shape()->getGlobalBounds().height;
			break;
		}
		case EValueType::Float: break;
		case EValueType::Double: break;
		case EValueType::String: break;
		case EValueType::List: break;
		case EValueType::Vector: break;
		case EValueType::Object: break;
		}
	}
}
Engine::Object* Engine::Editor::Editor::ObjectEdit()
{
	return currentObjectEdit;
}
std::vector<Engine::UI::UIElement> Engine::Editor::Editor::Element() const
{

}
#pragma endregion
