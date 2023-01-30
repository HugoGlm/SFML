#pragma once
#include <type_traits>

template<typename T> struct RemovePointer { using Type = T; };
template<typename T> struct RemovePointer<T*> { using Type = T; };