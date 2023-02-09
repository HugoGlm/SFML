#pragma once
#include "../../Engine/Component/Component.h"

namespace Test
{
	UCLASS();
	class PlayerComponent : public Engine::Component
	{
		DECLARE_CLASS_INFO(PlayerComponent, Component)
	public:
		PlayerComponent() = default;
		UFUNCTION() void update();
REGISTER_METHOD(update, &PlayerComponent::update, {}, BindingFlags::Public)

	};
}
