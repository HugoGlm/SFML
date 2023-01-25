#pragma once
#include "../../PrimaryType/Boolean/Boolean.h"

template<typename T>
struct IsPointer { static inline Engine::PrimaryType::Boolean Value = false; };

template<typename T>
struct IsPointer<T*> { static inline Engine::PrimaryType::Boolean Value = true; };

template<typename T>
struct IsPointer<const T> { static inline Engine::PrimaryType::Boolean Value = IsPointer<T>::Value; };

template<typename Base, typename T>
bool IsSame(T)
{
	return std::is_same_v<Base, T>;
}

template<typename Base, typename Derived>
bool IsSame(Derived* _der)
{
	Base* _cast = (Base*)_der;
	return _cast != nullptr;
}