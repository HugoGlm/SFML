#include "ReflectionTest.h"
#include "../../Engine/Utils/DebugMacro.h"
#include "../../Engine/Reflection/Field/FieldInfo.h"
#include <format>

void Test::ReflectionTest::Update()
{
	LOG("Update call !")
}

void Test::ReflectionTest::Display(const std::string& _msg)
{
	LOG(_msg);
}

void Test::ReflectionTest::Test()
{
	ReflectionTest test = ReflectionTest();
	test.Invoke<void>("Update");

	/*ReflectionTest test = ReflectionTest();

	Engine::Reflection::FieldInfo* _field = test.GetField("name");
	LOG("[Reflection][Test] => GetField(name)")
		checkLow((_field != nullptr), "[Reflection][Test] => field is nullptr")
		LOG(std::format("{}: {}", _field->Name(), _field->ToString().ToCstr()))

		std::vector<Engine::Reflection::FieldInfo*> _fields = test.Fields(BindingFlags::Public);
	LOG("[Reflection][Test] => Fields with Public flags")
		for (const Engine::Reflection::FieldInfo* _fieldInfo : _fields)
			LOG(std::format("{}: {}", _fieldInfo->Name(), _fieldInfo->ToString().ToCstr()))

			_fields = test.Fields(BindingFlags::Static);
	_fields = test.Fields(BindingFlags::Static);
	LOG("[Reflection][Test] => Fields with Static flags")
		for (const Engine::Reflection::FieldInfo* _fieldInfo : _fields)
			LOG(std::format("{}: {}", _fieldInfo->Name(), _fieldInfo->ToString().ToCstr()))

			_field->SetValue<Engine::PrimaryType::String>(new Engine::PrimaryType::String("best prof"));

	LOG(std::format("{}: {}", _field->Name(), _field->ToString().ToCstr()))
		LOG(test.name)*/
}
