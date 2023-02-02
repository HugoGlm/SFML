#include "Vector2.h"
#include "../Boolean/Boolean.h"
#include "../String/String.h"

#pragma region const
Engine::PrimaryType::Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}
#pragma endregion

#pragma region methods
Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::MoveToward(const Vector2& _current, const Vector2& _target, float _dt)
{
	const float _x = _target.x - _current.x;
	const float _y = _target.y - _current.y;

	const float _distance = _x * _x + _y * _y;
	if (_distance == 0 || (_dt >= 0 && _distance <= _dt * _dt))
		return _target;

	const float _dist = sqrt(_distance);
	return Vector2(_current.x + _x / _dist * _dt, _current.y + _y / _dist * _dt);
}
Engine::PrimaryType::String Engine::PrimaryType::Vector2::ToString() const
{
	return std::format("({}, {})", x, y).c_str();
}
void Engine::PrimaryType::Vector2::SerializeField(std::ostream& _os, const String& _fieldName, int _index)
{
	if (String::IsNullOrEmpty(_fieldName))
		_os << "\"" << ToString().ToCstr() << "\"";
	else
		_os << std::string("\"") + _fieldName.ToString().ToCstr() + "\" : \"" + ToString().ToCstr() + "\"";
}
void Engine::PrimaryType::Vector2::DeSerializeField(std::istream& _is, const String& _fieldName)
{
	std::string _line;
	while (std::getline(_is, _line))
	{
		if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
		{
			String _str = _line.c_str();
			_str = _str.SubString(_str.FindFirstOf('('), _str.FindFirstOf(')'));
			String _x = _str.SubString(_str.FindFirstOf('(') + 1, _str.FindFirstOf(','));
			String _y = _str.SubString(_str.FindFirstOf(' ') + 1);
			*this = Vector2(std::stof(_x.ToCstr()), std::stof(_y.ToCstr()));
			break;
		}
	}
}
#pragma endregion

#pragma region operator
Engine::PrimaryType::Vector2::operator sf::Vector2<float>() const
{
	return sf::Vector2f(x, y);
}
Engine::Object& Engine::PrimaryType::Vector2::operator=(const Object* _obj)
{
	const Vector2* _other = dynamic_cast<const Vector2*>(_obj);
	if (_other == nullptr)
		return *this;
	super::operator=(_obj);
	x = _other->x;
	y = _other->y;
	return *this;
}
Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator=(const Vector2& _other)
{
	x = _other.x;
	y = _other.y;
	return *this;
}
Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator+=(const Vector2& _other)
{
	x += _other.x;
	y += _other.y;
	return *this;
}
Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator-=(const Vector2& _other)
{
	x -= _other.x;
	y -= _other.y;
	return *this;
}
Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator/=(const Vector2& _other)
{
	x /= _other.x;
	y /= _other.y;
	return *this;
}
Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator*=(const Vector2& _other)
{
	x *= _other.x;
	y *= _other.y;
	return *this;
}
Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator+(const Vector2& _other) const
{
	Vector2 _res = *this;
	_res += _other;
	return _res;
}
Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator-(const Vector2& _other) const
{
	Vector2 _res = *this;
	_res -= _other;
	return _res;
}
Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator/(const Vector2& _other) const
{
	Vector2 _res = *this;
	_res /= _other;
	return _res;
}
Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator*(const Vector2& _other) const
{
	Vector2 _res = *this;
	_res *= _other;
	return _res;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Vector2::operator==(const Vector2& _other) const
{
	return x == _other.x && y == _other.y;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Vector2::operator!=(const Vector2& _other) const
{
	return !this->operator==(_other);
}
Engine::PrimaryType::Float& Engine::PrimaryType::Vector2::operator[](size_t _index)
{
	switch (_index)
	{
	case 0:
		return x;
	case 1:
		return y;
	default:
		throw std::exception("[Vector2] => operator[] index out of range");
	}
}
Engine::PrimaryType::Float Engine::PrimaryType::Vector2::operator[](size_t _index) const
{
	switch (_index)
	{
	case 0:
		return x;
	case 1:
		return y;
	default:
		throw std::exception("[Vector2] => operator[] index out of range");
	}
}
#pragma endregion