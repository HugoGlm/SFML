#pragma once
#include "../Delegate/Delegate.h"

namespace Engine::Event
{
	template<typename Res, typename... Params>
	class ActionInternal : public Object
	{
		DECLARE_CLASS_INFO(ActionInternal, Object)
#pragma region f/p
	private:
		std::vector<Deleagte<Res, Params...>> delegates = std::vector<Deleagte<Res, Params...>>();
#pragma endregion
#pragma region constructor
	public:
		ActionInternal(nullptr_t)
		{
			delegates.clear();
		}
		template<typename Class>
		ActionInternal(Class* _instance, Res(Class::* ptr)(Params...)
		{
			checkBaseOf(Object, Class)
				delegates.push_back(Delegate<Res, Params...>(_instance, ptr));
		}
#pragma endregion
#pragma region methods
	public:
		template<typename Class>
		void AddDynamic(Class* _instance, Res(Class::* ptr)(Params...))
		{
			checkBaseOf(object, Class)
				delegates.push_back(delegate<Res, Params...>(_instance, ptr));
		}
		template<typename Class>
		void RemoveDynamic(Class* _instance, Res(Class::* ptr)(Params...))
		{
			checkBaseOf(Object, Class)
				std::vector<delegate<Res, Params...>>::iterator it = delegates.begin();
			for (; it != delegates.end(); it++)
			{
				if (*it.GetAdress() == (void*&)ptr && *it.Instance() == _instance)
				{
					delegates.erase(it);
					break;
				}
			}
		}
		Res Invoke(Params... _params)
		{
			if constexpr (std::is_same_v<Res, void>)
			{ 
				for (Delegate<Res, Params...> _delegate : delegates)
					_delegate.Invoke(_params...);
				return Res();
			}
			else
			{
				Res _result = Res();
				for (Delegate<Res, Params...> _delegate : delegates)
					_result = _delegate.Invoke(_params...);
				return _result;
			}
		}
#pragma endregion
#pragma region operator
	public:
		ActionInternal& operator=(nullptr)
		{
			delegates.clear();
			return *this;
		}
		ActionInternal& operator=(const Action& _other)
		{
			delegates = _other.delegates;
			return *this;
		}
		Res operator()(Params... _params)
		{
			return Invoke(_params...);
		}
#pragma endregion

	};
}

template<typename... Params>
using Action = Engine::Event::ActionInternal<void, Params...>;
template<typename T, typename... Params>
using Func = Engine::Event::ActionInternal<T, Params...>;
template<typename... Params>
using Predicate = Engine::Event::ActionInternal<bool, Params...>;
