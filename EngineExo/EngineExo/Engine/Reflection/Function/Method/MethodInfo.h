#pragma once
#include "../Function.h"
#include "../../Flags/BindingFlags.h"
#include <exception>

namespace Engine
{
	class Object;
}

namespace Engine::Reflection
{
	template<typename Res, typename... Params>
	class MethodInfo : public Function
	{
#pragma region f/p
	private:
		typedef Res(Object::* FunctionType)(Params...);
		FunctionType function = nullptr;
		BindingFlags flags = BindingFlags::NoPublic;
#pragma endregion
#pragma region constructor
	public:
		MethodInfo() = default;
		template<typename Class>
		MethodInfo(const std::string& _name, Res(Class::* ptr)(Params...), const std::vector<ParameterInfo*>& _params, const BindingFlags& _flags)
			: Function(_name, _params)
		{
			if constexpr (!std::is_base_of_v<Object, Class>)
				throw std::exception("Class must be inherited of object");
			function = reinterpret_cast<FunctionType>(ptr);
			flags = _flags;
		}
#pragma endregion
#pragma region methods
	public:
		BindingFlags Flags() const
		{
			return flags;
		}
		Res Invoke(Object* _instance, Params... _params)
		{
			return (_instance->*function)(_params...);
		}
		void* GetAddress() const
		{
			return (void*&)&function;
		}
#pragma endregion
#pragma region operator
	public:
		bool operator==(nullptr_t)
		{
			return function == nullptr;
		}
		bool operator!=(nullptr_t)
		{
			return function != nullptr;
		}

		bool operator==(const MethodInfo& _other)
		{
			return GetAddress() == _other.GetAddress();
		}
		bool operator!=(const MethodInfo& _other)
		{
			return GetAddress() != _other.GetAddress();
		}

		template<typename Class>
		bool operator==(Res(Class::* ptr)(Params...))
		{
			return GetAddress() == (void*&)ptr;
		}
		template<typename Class>
		bool operator!=(Res(Class::* ptr)(Params...))
		{
			return GetAddress() != (void*&)ptr;
		}
#pragma endregion

	};
}

