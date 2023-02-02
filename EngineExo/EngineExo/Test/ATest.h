#pragma once
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Float/Float.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
#include "../Engine/PrimaryType/Double/Double.h"
#include "../Engine/PrimaryType/String/String.h"
#include "../Engine/PrimaryType/Vector2/Vector2.h"
#include "../Engine/PrimaryType/List/List.h"

namespace Test
{
	UCLASS()
	class ATest : public Engine::Object
	{
	private:
		UPROPERTY() Engine::PrimaryType::Integer age = 10;
REGISTER_FIELD(age, &age, BindingFlags::NoPublic)
		UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::String> names = { "Nounours", "Tchoupi", "Dora", "Sacha Ketchup" };
REGISTER_FIELD(names, &names, BindingFlags::NoPublic)
	};
}
