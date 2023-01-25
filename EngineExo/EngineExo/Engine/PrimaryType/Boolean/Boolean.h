#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Boolean : public ValueType
	{
		DECLARE_CLASS_INFO(Boolean, ValueType)
#pragma region f/p
	private:
		bool value = false;
#pragma endregion
#pragma region constructor
	public:
		Boolean() = default;
		Boolean(bool _value);
		Boolean(const Boolean& _copy);
#pragma endregion
#pragma region override
	public:
		PrimaryType::String ToString() const override;
#pragma endregion
#pragma region operator
	public:
		Boolean& operator=(const Boolean& _other);
		Boolean operator!() const;
		operator bool();
		operator bool() const;
#pragma endregion

	};
}

