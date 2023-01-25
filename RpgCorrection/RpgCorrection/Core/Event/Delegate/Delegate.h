#pragma once
#include "../../Object/Object.h"
#include "../../Utils/Debug/Debug.h"
namespace Core
{
	namespace Event
	{
		template<typename Res, typename... Params>
		class Delegate : public Object
		{
			DECLARE_CLASS_INFO(Delegate, Object)
#pragma region f/p
		private:
			typedef Res(Object::* Function)(Params...);
			Function function = nullptr;
			Object* instance = nullptr;
#pragma endregion f/p
#pragma region constructor
		public:
			Delegate(nullptr_t)
			{
				instance = nullptr;
				function = nullptr;
			}
			Delegate(const Delegate& _copy)
			{
				instance = _copy.instance;
				function = _copy.function;
			}
			template<typename Class>
			Delegate(Class* _instance, Res(Class::* ptr)(Params...))
			{
				checkBaseOf(Object, Class)
				instance = _instance;
				function = reinterpret_cast<Function>(ptr);
			}
#pragma endregion constructor
#pragma region methods
		public:
			template<typename Class>
			void SetDynamic(Class* _instance, Res(Class::* ptr)(Params...))
			{
				checkBaseOf(Object, Class)
				instance = _instance;
				function = reinterpret_cast<Function>(ptr);
			}

			bool IsValid() const
			{
				return instance != nullptr && function != nullptr;
			}

			Res Invoke(Params... _params)
			{
				return (instance->*function)(_params...);
			}
#pragma endregion methods
#pragma region operator
		public:
			Delegate& operator=(nullptr_t)
			{
				instance = nullptr;
				function = nullptr;
				return *this;
			}

			Delegate& operator=(const Delegate& _other)
			{
				instance = _other.instance;
				function = _other.function;
				return *this;
			}

#pragma endregion operator
		};
	}
}