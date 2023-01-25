#pragma once
#include "../../Object/Object.h"
#include <string>

template<typename Res, typename... Params>
class Delegate : public Object
{
#pragma region f/p
private:
	typedef Res(Object::* Function)(Params...);
	Function function = nullptr;
	Object* instance = nullptr;
#pragma endregion
#pragma region constructor
public:
	Delegate(nullptr_t)
	{
		function = nullptr;
		instance = nullptr;
	}
	Delegate(const Delegate& _copy)
	{
		function = _copy.function;
		instance = _copy.instance;
	}
	template<typename Class>
	Delegate(Class* _instance, Res(Class::* ptr)(Params...))
	{
		if constexpr (!std::is_base_of_v <Object, Class>)
			throw std::exception("Class must be inherited of Object");
		instance = _instance;
		function = reinterpret_cast<Function>(ptr);
	}
#pragma endregion
#pragma region methods
public:
	bool IsValid() const
	{
		return instance != nullptr && function != nullptr;
	}
	template<typename Class>
	void SetDynamic(Class* _instance, Res(Class::* ptr)(Params...))
	{
		*this = Delegate(_instance, ptr);
	}
	void SetDynamic(nullptr_t)
	{
		*this = Delegate(nullptr);
	}
	Res Invoke(Params... _params)
	{
		if (instance == nullptr)
			throw std::exception("instance is nullptr");
		if (function == nullptr)
			throw std::exception("function is nullptr");
		return (instance->*function)(_params...);
	}
#pragma endregion
#pragma region operator
public:
	void operator=(const Delegate& _other)
	{
		function = _other.function;
		instance = _other.instance;
	}

	void operator=(nullptr_t)
	{
		instance = nullptr;
		function = nullptr;
	}
#pragma endregion

};