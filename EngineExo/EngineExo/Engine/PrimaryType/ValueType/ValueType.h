#pragma once
#include "../../Object/Object.h"
#include "../../Reflection/Utils/ReflectionUtils.h"

namespace Engine::PrimaryType
{
	class ValueType : public Engine::Object
	{
		DECLARE_CLASS_INFO_FLAGS(ValueType, Object, ClassFlags::Type)
#pragma region constructor
	public:
		ValueType() = default;
		~ValueType() override = default;
#pragma endregion
#pragma region operator
	public:
		virtual Object& operator=(const Object* _other) override
		{
			return super::operator=(_other);
		}
#pragma endregion

	};
}


