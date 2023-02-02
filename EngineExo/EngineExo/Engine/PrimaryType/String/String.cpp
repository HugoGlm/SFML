#include "String.h"
#include "../Boolean/Boolean.h"
#include "../../Utils/Template/Template.h"
#include <iostream>

#pragma region constructor
Engine::PrimaryType::String::String(const char* _value) : super()
{
	if (value == nullptr)
		value = "";
	const size_t _otherLength = strlen(_value);
	const size_t _newLength = length + _otherLength;
	char* _array = new char[_newLength + 1];
	strcpy(_array, value);
	strcat(_array, _value);
	value = _array;
	length = _newLength;
}
Engine::PrimaryType::String::String(const String& _copy) : super(_copy)
{
	if (_copy.value == nullptr)
		return;
	length = _copy.length;
	char* _array = new char[length + 1];
	memcpy(_array, _copy.value, length + 1);
	value = _array;
}
#pragma endregion

#pragma region methods
Engine::PrimaryType::Boolean Engine::PrimaryType::String::StartWith(char _c) const
{
	return value[0] == _c;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::EndWith(char _c) const
{
	return value[length - 1] == _c;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::StartWith(const String& _str) const
{
	for (size_t i = 0; i < length; i++)
		if (value[i] != _str.value[i])
			return false;
	return true;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::EndWith(const String& _str) const
{
	const size_t _otherLength = _str.length;
	for (size_t i = _otherLength; i > 0; i--)
		if (value[length - i] != _str.value[_otherLength - i])
			return false;
	return true;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::EqualsIgnoreCase(const String& _str) const
{
	if (length != _str.length) return false;
	return ToLower() == _str.ToLower();
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::Contains(const String& _str) const
{
	const std::string& _string = value;
	return _string.find(_str.value) != std::string::npos;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::IsNullOrEmpty(const String& _str)
{
	return _str.value == nullptr || _str.length == 0;
}
Engine::PrimaryType::String Engine::PrimaryType::String::ToLower() const
{
	char* _array = new char[length];
	for (int i = 0; i < length; i++)
		_array[i] = std::tolower(value[i]);
	return _array;
}
Engine::PrimaryType::String Engine::PrimaryType::String::ToUpper() const
{
	char* _array = new char[length];
	for (int i = 0; i < length; i++)
		_array[i] = std::toupper(value[i]);
	return _array;
}
Engine::PrimaryType::String Engine::PrimaryType::String::SubString(size_t _begin) const
{
	return SubString(_begin, Length());
}
Engine::PrimaryType::String Engine::PrimaryType::String::SubString(size_t _begin, size_t _end) const
{
	String _result = "";
	for (size_t i = _begin; i < _end; ++i)
		_result += value[i];
	return _result;
}
Engine::PrimaryType::String Engine::PrimaryType::String::Replace(const String& _old, const String& _new) const
{
	std::string _str = value;
	size_t _startPos = 0;
	const std::string& _from = _old.value;
	const std::string& _to = _new.value;
	while ((_startPos = _str.find(_from, _startPos)) != std::string::npos)
	{
		_str.replace(_startPos, _from.length(), _to);
		_startPos += _to.length();
	}
	return _str.c_str();
}
Engine::PrimaryType::String Engine::PrimaryType::String::Replace(char _old, char _new)
{
	char* _array = new char[length];
	strcpy(_array, value);
	for (int i = 0; i < length; i++)
	{
		if (value[i] == _old)
			_array[i] = _new;
	}
	return _array;
}
Engine::PrimaryType::String Engine::PrimaryType::String::Trim() const
{
	return Replace(" ", "");;
}
int Engine::PrimaryType::String::FindFirstOf(char _c)
{
	for (int i = 0; i < length; i++)
		if (value[i] == _c)
			return i;
	return -1;
}
int Engine::PrimaryType::String::FindLastOf(char _c)
{
	int _result = -1;
	for (int i = 0; i < length; i++)
		if (value[i] == _c)
			_result = i;
	return _result;
}
size_t Engine::PrimaryType::String::Length() const
{
	return length;
}
void Engine::PrimaryType::String::Append(const char* _str)
{
	Append(String(_str));
}
void Engine::PrimaryType::String::Append(char _c)
{
	const size_t _newLegth = length + 2;
	char* _array = new char[_newLegth];
	strcpy(_array, value);
	_array[length] = _c;
	_array[length + 1] = '\0';
	value = _array;
	length += 1;
}
void Engine::PrimaryType::String::Append(const String& _str)
{
	const size_t _newLength = length = _str.length;
	char* _array = new char[_newLength + 1];
	strcpy(_array, value);
	strcat(_array, _str.value);
	value = _array;
	length = _newLength;
}
Engine::PrimaryType::String Engine::PrimaryType::String::ToString() const
{
	return value;
}
void Engine::PrimaryType::String::SerializeField(std::ostream& _os, const String& _fieldName, int _index)
{
	if (IsNullOrEmpty(_fieldName))
		_os << "\"" << ToString().ToCstr() << "\"";
	else
		_os << std::string("\"") + _fieldName.ToString().ToCstr() + "\" : \"" + ToString().ToCstr() + "\"";
}
void Engine::PrimaryType::String::DeSerializeField(std::istream& _is, const String& _fieldName)
{
	std::string _line;
	while (std::getline(_is, _line))
	{
		if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
		{
			String _str = _line.c_str();
			_str = _str.SubString(_str.FindFirstOf(':'));
			_str = _str.SubString(_str.FindFirstOf('"'), _str.FindLastOf('"')).Replace("\"", "");
			*this = _str;
			break;
		}
	}
}
const char* Engine::PrimaryType::String::ToCstr() const
{
	return value;
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::PrimaryType::String::operator=(const Object* _other)
{
	if (!IsSame<String>(_other))
		return *this;
	super::operator=(_other);
	const String* _string = dynamic_cast<const String*>(_other);
	value = _string->value;
	length = _string->length;
	return *this;
}
Engine::PrimaryType::String& Engine::PrimaryType::String::operator+=(const char* _str)
{
	Append(_str);
	return *this;
}
Engine::PrimaryType::String& Engine::PrimaryType::String::operator+=(char _c)
{
	Append(_c);
	return *this;
}
Engine::PrimaryType::String& Engine::PrimaryType::String::operator+=(const String& _str)
{
	Append(_str);
	return *this;
}
Engine::PrimaryType::String& Engine::PrimaryType::String::operator=(const String& _other)
{
	value = _other.value;
	length = _other.length;
	return *this;
}
Engine::PrimaryType::String::operator const char* ()
{
	return value;
}
Engine::PrimaryType::String::operator const char* () const
{
	return value;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::operator==(const String& _str) const
{
	if (length != _str.length)
		return false;
	for (int i = 0; i < length; i++)
		if (value[i] != _str.value[i])
			return false;
	return true;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::operator!=(const String& _str) const
{
	return !this->operator==(_str);
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::operator==(const char* _str) const
{
	if (length != strlen(_str))
		return false;
	for (int i = 0; i < length; i++)
		if (value[i] != _str[i])
			return false;
	return true;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::String::operator!=(const char* _str) const
{
	return !this->operator==(_str);
}
#pragma endregion

