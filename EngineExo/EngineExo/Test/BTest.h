#pragma once
#include"../Engine/Object/Object.h"
#include"../Engine/PrimaryType/List/List.h"
#include"../Engine/PrimaryType/Integer/Integer.h"

namespace Test
{
	UCLASS()
	class BTest : public Engine::Object
	{
	private:
		UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::Integer> integers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
REGISTER_FIELD(integers, &integers, BindingFlags::NoPublic)
	};
}
