#pragma once
#include "../Object/Object.h"
#include "../UI/Element/UIElement.h"
#include "../PrimaryType/Vector2/Vector2.h"
#include <vector>

namespace Engine::Editor
{
	enum class EValueType
	{
		Int,
		Bool,
		Float,
		Double,
		String,
		List,
		Vector,
		Object
	};
	class Editor : public Object
	{
		DECLARE_CLASS_INFO(Editor, Object)
#pragma region f/p
	private:
		std::vector<UI::UIElement*> elements = std::vector<UI::UIElement*>();
		Object* currentObjectEdit = nullptr;
		PrimaryType::Vector2 currentPosition = PrimaryType::Vector2(0, 0);
		PrimaryType::Vector2 initialPosition = PrimaryType::Vector2(0, 0);
#pragma endregion
#pragma region constructor
	public:
		Editor() = default;
		Editor(Object* _object);
#pragma endregion
#pragma region methods
	public:
		EValueType GetValueType(Object* _object);
		void SetObjectEdit(Object* _object);
		void SetPosition(const PrimaryType::Vector2& _position);
		virtual void InspectorGUI();
		Object* ObjectEdit();
		std::vector<UI::UIElement> Element() const;
#pragma endregion

	};
}
