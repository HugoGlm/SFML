#include "Console.h"
#include "../../PrimaryType/String/String.h"
#include <iostream>

#pragma region methods
void Engine::Utils::Console::Log(const std::string& _msg)
{
	std::cout << "[Log] => " << _msg << std::endl;
}
void Engine::Utils::Console::Log(const Object& _obj)
{
	std::cout << "[Log] => " << _obj.ToString() << std::endl;
}
void Engine::Utils::Console::Log(const ILogger* _obj)
{
	std::cout << "[Log] => " << _obj->ToString() << std::endl;
}
void Engine::Utils::Console::LogWarning(const std::string& _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_yellow);
	std::cout << "[Warning] => " << _msg << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}
void Engine::Utils::Console::LogWarning(const Object& _obj)
{
	SetConsoleTextAttribute(consoleHandle, color_yellow);
	std::cout << "[Warning] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}
void Engine::Utils::Console::LogWarning(const ILogger* _obj)
{
	SetConsoleTextAttribute(consoleHandle, color_yellow);
	std::cout << "[Warning] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}
void Engine::Utils::Console::LogError(const std::string& _msg)
{
	SetConsoleTextAttribute(consoleHandle, color_red);
	std::cout << "[Error] => " << _msg << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}
void Engine::Utils::Console::LogError(const Object& _obj)
{
	SetConsoleTextAttribute(consoleHandle, color_red);
	std::cout << "[Error] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}
void Engine::Utils::Console::LogError(const ILogger* _obj)
{
	SetConsoleTextAttribute(consoleHandle, color_red);
	std::cout << "[Error] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, color_white);
}
#pragma endregion

