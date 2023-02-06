#pragma once
#include "../Object/Object.h"
#include "../Event/Action/Action.h"

namespace Engine
{
	class Selection : public Object
	{
		DECLARE_CLASS_INFO(Selection, Object)
#pragma region f/p
	private:
		static inline Object* selected = nullptr;
	public:
		static inline Action<Object*> OnSelectionChanged = nullptr;
#pragma endregion
#pragma region methods
	public:
		static void SetSelection(Object* _obj);
		static Object* GetSelected();
#pragma endregion

	};
}

