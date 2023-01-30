#pragma once
#include "../PrimaryType/String/String.h"

#define INDEX_NONE -1

template<typename T>
Engine::PrimaryType::String ToString(T _item)
{
	if constexpr (std::is_base_of_v<Engine::Object, T>)
	{
		return _item.ToString();
	}
	else
	{
		return std::to_string(_item).c_str();
	}
}

template<typename T>
Engine::PrimaryType::String ToString(T* _item)
{
	return _item->ToString();
}