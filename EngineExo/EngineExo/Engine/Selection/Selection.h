#pragma once
#include "../Utils/Singleton/Singleton.h"
#include "../Object/Object.h"
#include "../Event/Action/Action.h"

namespace Engine
{
	class Selection : public Utils::Singleton<Selection>
	{
		DECLARE_CLASS_INFO(Selection, Singleton<Selection>)
#pragma region f/p
	private:
		Object* selected = nullptr;
	public:
		static inline Action<Object*> OnSelectionChanged = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Selection() = default;
#pragma endregion

#pragma region methods
	public:
		void SetSelection(Object* _obj);
		Object* GetSelected();
#pragma endregion

	};
}

