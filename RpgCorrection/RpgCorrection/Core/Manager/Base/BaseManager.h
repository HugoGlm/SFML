#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include "../../Utils/Debug/Debug.h"
#include <map>
#include <ranges>
#include <format>

namespace Core
{
	namespace Manager
	{
		template<typename Class, typename Item>
		class BaseManager : public Utils::Singleton<Class>
		{
			DECLARE_CLASS_INFO(BaseManager, Utils::Singleton<Class>)
#pragma region f/p
		protected:
			std::map<std::string, Item*> items = std::map<std::string, Item*>();
#pragma endregion
#pragma region methods
		public:
			virtual void Init() = 0;
			virtual Item* Load(const char* _name);
#pragma endregion
#pragma region override
		protected:
			void OnDestroy() override;
#pragma endregion
		};
		template<typename Class, typename Item>
		Item* BaseManager<Class, Item>::Load(const char* _name)
		{
			check(items.contains(_name), std::format("[BaseManager] => doesn't found key: {}", _name), nullptr);
				return items[_name];
		}
		template<typename Class, typename Item>
		void BaseManager<Class, Item>::OnDestroy()
		{
			for (Item*& _item : items | std::ranges::views::values)
			{
				delete _item;
				_item = nullptr;
			}
			items.clear();
		}
	}
}
