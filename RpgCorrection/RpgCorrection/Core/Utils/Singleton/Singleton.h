#pragma once
#include "../../Object/Object.h"

namespace Core
{
	namespace Utils
	{
		template<typename T>
		class Singleton : public Object
		{
			DECLARE_CLASS_INFO(Singleton, Object)
		private:
			static inline T* instance = nullptr;
		public:
			Singleton() = default;
			Singleton(const Singleton&) = delete;
		public:
			static T* Instance()
			{
				if (instance == nullptr)
					instance = new T();
				return instance;
			}
			void Destroy()
			{
				OnDestroy();
				delete instance;
				instance = nullptr;
			}
		protected:
			virtual void OnDestroy() { }
		};
	}
}