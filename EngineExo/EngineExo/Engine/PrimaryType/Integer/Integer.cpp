#include "Integer.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "../../Utils/Template/Template.h"

#pragma region f/p
const Engine::PrimaryType::Integer Engine::PrimaryType::Integer::MinValue = INT_MIN;
const Engine::PrimaryType::Integer Engine::PrimaryType::Integer::MaxValue = INT_MAX;
#pragma endregion

#pragma region constructor
Engine::PrimaryType::Integer::Integer(int _value)
{
	value = _value;
}
Engine::PrimaryType::Integer::Integer(const Integer& _copy)
{
	value = _copy.value;
}
#pragma endregion

#pragma region methods
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::Parse(const String& _str)
{
	return std::stoi(_str.ToCstr());
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::TryParse(const String& _str, Integer& _output)
{
	try
	{
		_output = std::stoi(_str.ToCstr());
		return true;
	}
	catch (...)
	{
		_output = -1;
		return false;
	}
}
#pragma endregion

#pragma region override
Engine::PrimaryType::String Engine::PrimaryType::Integer::ToString() const
{
	return std::to_string(value).c_str();
}
void Engine::PrimaryType::Integer::SerializeField(std::ostream& _os, const String& _fieldName)
{
	if (String::IsNullOrEmpty(_fieldName))
		_os << std::string("\"") + ToString().ToCstr() + "\"";
	else
		_os << std::string("\"") + _fieldName.ToString().ToCstr() + "\" : \"" + ToString().ToCstr() + "\"";
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::PrimaryType::Integer::operator=(const Object* _other)
{
	if (!IsSame<Integer>(_other))
		return *this;
	super::operator=(_other);
	const Integer* _integer = dynamic_cast<const Integer*>(_other);
	value = _integer->value;
	return *this;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator=(const Integer& _other)
{
	value = _other.value;
	return *this;
}
Engine::PrimaryType::Integer::operator int()
{
	return value;
}
Engine::PrimaryType::Integer::operator int() const
{
	return value;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator>(int _other) const
{
	return value > _other;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator>=(int _other) const
{
	return value >= _other;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator<(int _other) const
{
	return value < _other;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator<=(int _other) const
{
	return value <= _other;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator==(int _other) const
{
	return value == _other;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator!=(int _other) const
{
	return value != _other;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator+(int _other) const
{
	return value + _other;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator-(int _other) const
{
	return value - _other;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator*(int _other) const
{
	return value * _other;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator%(int _other) const
{
	return value % _other;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator/(int _other)
{
	return value / _other;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator+=(int _other)
{
	value += _other;
	return *this;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator-=(int _other)
{
	value -= _other;
	return *this;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator*=(int _other)
{
	value *= _other;
	return *this;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator/=(int _other)
{
	value /= _other;
	return *this;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator%=(int _other)
{
	value %= _other;
	return *this;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator++()
{
	++value;
	return *this;
}
Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator--()
{
	--value;
	return *this;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator++(int)
{
	const int _result = value;
	operator++();
	return _result;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator--(int)
{
	const int _result = value;
	operator--();
	return _result;
}
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator-()
{
	return -value;
}
#pragma endregion

