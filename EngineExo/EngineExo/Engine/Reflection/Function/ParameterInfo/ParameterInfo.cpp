#include "ParameterInfo.h"
#include <format>

#pragma region constructor
Engine::Reflection::ParameterInfo::ParameterInfo(const std::string& _name, int _position)
{
	name = _name;
	position = _position;
}
#pragma endregion

#pragma region methods
std::string Engine::Reflection::ParameterInfo::Name() const
{
	return name;
}
int Engine::Reflection::ParameterInfo::Position() const
{
	return position;
}
#pragma endregion
