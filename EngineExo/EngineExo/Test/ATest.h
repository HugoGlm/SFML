#pragma once
#include "../Engine/Object/Object.h"
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/String/String.h"
#include "../Engine/Reflection/Function/ParameterInfo/ParameterInfo.h"

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

	public:
		UFUNCTION() void Test1(std::string t, size_t age);
REGISTER_METHOD(Test1, &ATest::Test1, (std::vector<Engine::Reflection::ParameterInfo*>{new Engine::Reflection::ParameterInfo("t", 0),new Engine::Reflection::ParameterInfo("age", 1)}), BindingFlags::Public)
	};
}
