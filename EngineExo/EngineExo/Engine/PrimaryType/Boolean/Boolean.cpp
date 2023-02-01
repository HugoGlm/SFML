#include "Boolean.h"
#include "../String/String.h"
#include <iostream>

#pragma region constructor
Engine::PrimaryType::Boolean::Boolean(bool _value) : super()
{
	value = _value;
}
Engine::PrimaryType::Boolean::Boolean(const Boolean& _copy) : super(_copy)
{
	value = _copy.value;
}
#pragma endregion

#pragma region override
Engine::PrimaryType::String Engine::PrimaryType::Boolean::ToString() const
{
	return value ? "true" : "false";
}
void Engine::PrimaryType::Boolean::SerializeField(std::ostream& _os, const String& _fieldName)
{
	if (String::IsNullOrEmpty(_fieldName))
		_os << std::string("\"") + ToString().ToCstr() + "\"";
	else
		_os << std::string("\"") + _fieldName.ToString().ToCstr() + "\" : \"" + ToString().ToCstr() + "\"";
}
void Engine::PrimaryType::Boolean::DeSerializeField(std::istream& _is, const String& _fieldName)
{
	std::string _line;
	while (std::getline(_is, _line))
	{
		if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
		{
			String _str = _line.c_str();
			_str = _str.SubString(_str.FindFirstOf(':'));
			_str = _str.SubString(_str.FindFirstOf('"'), _str.FindLastOf('"')).Replace("\"", "");
			*this = _str == "true";
			break;
		}
	}
}
#pragma endregion

#pragma region operator
Engine::PrimaryType::Boolean& Engine::PrimaryType::Boolean::operator=(const Boolean& _other)
{
	value = _other.value;
	return *this;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Boolean::operator!() const
{
	return !value;
}
Engine::PrimaryType::Boolean::operator bool()
{
	return value;
}
Engine::PrimaryType::Boolean::operator bool() const
{
	return value;
}
#pragma endregion

