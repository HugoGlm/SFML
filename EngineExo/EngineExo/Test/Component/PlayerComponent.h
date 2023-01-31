#pragma once
#include "../../Engine/Component/Component.h"

namespace Test
{
	UCLASS();
	class PlayerComponent : public Engine::Component
	{
	public:
		UFUNCTION() void update();
REGISTER_METHOD(update, &PlayerComponent::update, {}, BindingFlags::Public)
	};
}
