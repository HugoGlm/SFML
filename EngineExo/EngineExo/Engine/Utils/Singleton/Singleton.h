#pragma once
#include "../../Object/Object.h"

namespace Engine::Utils
{
	template<typename T>
	class Singleton : public Object
	{
		DECLARE_CLASS_INFO(Singleton<T>, Object)
#pragma region f/p
	private:
		static inline T* instance = nullptr;
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
#pragma region override
	public:
		PrimaryType::String ToString() const override
		{
			PrimaryType::String _result = "==========Window Settings==========\n";
			_result += PrimaryType::String("Name: ");
			_result += name;
			_result += "\nWidth: ";
			_result += width.ToString();
			_result += "\nHeight: ";
			_result += height.ToString();
			_result += "\n===================================\n";
			return _result;
		}
#pragma endregion

	};
}