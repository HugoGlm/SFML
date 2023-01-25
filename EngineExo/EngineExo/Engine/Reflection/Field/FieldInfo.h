#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../Flags/BindingFlags.h"

namespace Engine::Reflection
{
	UCLASS()
	class FieldInfo : public Object
	{
		DECLARE_CLASS_INFO(FieldInfo, Object)
#pragma region f/p
	private:
		PrimaryType::String name = "";
		Object* reflectedObject = nullptr;
		BindingFlags flags = BindingFlags::NoPublic;
#pragma endregion
#pragma region constructor
	public:
		FieldInfo() = default;
		FieldInfo(const PrimaryType::String& _name, Object* _reflectedObject, BindingFlags _flags);
#pragma endregion
#pragma region methods
	public:
		PrimaryType::Boolean IsPublic() const;
		PrimaryType::Boolean IsPrivate() const;
		PrimaryType::Boolean IsStatic() const;
		PrimaryType::Boolean IsArray() const;
		PrimaryType::Boolean IsReflectedClass() const;
		PrimaryType::String Name() const;
		BindingFlags Flags() const;
		Object* ReflectedObject();
#pragma endregion
#pragma region override
		PrimaryType::String ToString() const override;
		Object& operator=(const Object* _obj) override;
#pragma endregion

	};
}

