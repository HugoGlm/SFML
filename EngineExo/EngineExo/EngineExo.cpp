#include <iostream>
#include "Engine/Object/Object.h"
#include "Engine/PrimaryType/String/String.h"
#include "Engine/PrimaryType/Boolean/Boolean.h"
#include "Engine/Utils/DebugMacro.h"

int main()
{
	Engine::PrimaryType::String str = "";
	try
	{
		Engine::PrimaryType::Boolean b = str.Invoke<Engine::PrimaryType::Boolean, Engine::PrimaryType::String>("IsNullOrEmpty", nullptr, Engine::PrimaryType::String(""));
		LOG(b)
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}