#pragma once
#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/PrimaryType/Float/Float.h"
#include "../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../Engine/PrimaryType/Double/Double.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Vector2/Vector2.h"
#include "../../Engine/PrimaryType/List/List.h"

namespace Test
{
	UCLASS()
	class ATest : public Engine::Object
	{
	private:
		UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::Integer> integers = { 0, 1, 2, 3, 4, 5};
REGISTER_FIELD(integers, &integers, BindingFlags::NoPublic)

	};
}
