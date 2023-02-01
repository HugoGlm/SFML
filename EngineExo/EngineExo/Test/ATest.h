#pragma once
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Float/Float.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
#include "../Engine/PrimaryType/Double/Double.h"
#include "../Engine/PrimaryType/String/String.h"
#include "../Engine/PrimaryType/Vector2/Vector2.h"

namespace Test
{
	UCLASS()
	class ATest : public Engine::Object
	{
	private:
	UPROPERTY() Engine::PrimaryType::Boolean boolean = false;
REGISTER_FIELD(boolean, &boolean, BindingFlags::NoPublic)
	UPROPERTY() Engine::PrimaryType::Double doublee = 0;
REGISTER_FIELD(doublee, &doublee, BindingFlags::NoPublic)
	UPROPERTY() Engine::PrimaryType::Float floatt = 0.0f;
REGISTER_FIELD(floatt, &floatt, BindingFlags::NoPublic)
	UPROPERTY() Engine::PrimaryType::Integer integer = 0;
REGISTER_FIELD(integer, &integer, BindingFlags::NoPublic)
	UPROPERTY() Engine::PrimaryType::String string = "";
REGISTER_FIELD(string, &string, BindingFlags::NoPublic)
	UPROPERTY() Engine::PrimaryType::Vector2 vector2 = Engine::PrimaryType::Vector2(0, 0);
REGISTER_FIELD(vector2, &vector2, BindingFlags::NoPublic)
	};
}
