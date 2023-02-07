#pragma once
#include "../Component/Component.h"
#include "../PrimaryType/Vector2/Vector2.h"

namespace Engine
{
	UCLASS()
	class Transform : public Component
	{
		DECLARE_CLASS_INFO(Transform, Component)
#pragma region f/p
	public:
		UPROPERTY() PrimaryType::Vector2 position = PrimaryType::Vector2(0, 0);
REGISTER_FIELD(position, &position, BindingFlags::Public)
#pragma endregion
#pragma region constructor
	public:

#pragma endregion
#pragma region methods
		public:

#pragma endregion

	};
}

