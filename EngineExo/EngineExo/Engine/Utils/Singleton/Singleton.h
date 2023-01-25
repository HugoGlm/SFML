#pragma once
#include "../../Object/Object.h"

namespace Engine::utils
{
	template<typename T>
	class Singleton : public Object
	{
		DECLARE_CLASS_INFO(Singleton<T>, Object)
#pragma region f/p
	private:
		static T* instance = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Singleton() = default;
		Singleton(const Singleton&) = delete;
		~Singleton() override
		{
			OnDestroy();
		}
#pragma endregion
#pragma region methods
	public:
		static T* Instance()
		{
			if (instance == nullptr)
				instance = new T();
			return instance;
		}
		void Destroy()
		{
			delete instance;
			instance = nullptr;
		}
		virtual void OnDestroy() {}
#pragma endregion

	};
}