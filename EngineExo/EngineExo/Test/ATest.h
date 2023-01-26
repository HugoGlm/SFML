#pragma once
#include "../Engine/Object/Object.h"
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/String/String.h"

namespace Test
{
	UCLASS()
	class ATest : public Engine::Object
	{
	private:
		UPROPERTY() static inline Engine::PrimaryType::String name = "";
REGISTER_FIELD(name, &name, BindingFlags::NoPublic | BindingFlags::Static)
	public:
		UPROPERTY() Engine::PrimaryType::Integer age = 0;
REGISTER_FIELD(age, &age, BindingFlags::Public)
	};
}

