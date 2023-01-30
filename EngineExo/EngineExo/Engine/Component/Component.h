#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/Boolean/Boolean.h"

namespace Engine
{
	class GameObject;
	UCLASS()
	class Component : public Object
	{
		DECLARE_CLASS_INFO(Component, Object)
#pragma region f/p
	public:
		UPROPERTY() PrimaryType::Boolean enabled = true;
REGISTER_FIELD(enabled, &enabled, BindingFlags::Public)
		UPROPERTY() GameObject* gameobject = nullptr;
REGISTER_FIELD(gameobject, gameobject, BindingFlags::Public)
#pragma endregion
#pragma region constructor
	public:
		Component() = default;
		Component(const Component&) = default;
		~Component() override = default;
#pragma endregion
#pragma region operator
	public:
		Object& operator=(const Object* _obj) override;
#pragma endregion
	};
}

