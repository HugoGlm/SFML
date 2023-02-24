#include "UUID.h"
#include <guiddef.h>
#include <combaseapi.h>

#pragma region constructor
Engine::PrimaryType::FGuid::FGuid(int _a, int _b, int _c, int _d)
{
	a = _a;
	b = _b;
	c = _c;
	d = _d;
}
Engine::PrimaryType::FGuid::FGuid(const FGuid& _copy)
{
	a = _copy.a;
	b = _copy.b;
	c = _copy.c;
	d = _copy.d;
}
#pragma endregion

#pragma region methods
Engine::PrimaryType::FGuid Engine::PrimaryType::FGuid::NewGuid()
{
	FGuid _result(0, 0, 0, 0);
	CoCreateGuid((GUID*)&_result);
	return _result;
}
#pragma endregion

#pragma region override
Engine::PrimaryType::String Engine::PrimaryType::FGuid::ToString() const
{
	return std::format("%08X-%08X-%08X-%08X", a, b, c, d).c_str();
}
void Engine::PrimaryType::FGuid::SerializeField(std::ostream& _os, const String& _fieldName, int _index)
{
	ValueType::SerializeField(_os, _fieldName, _index);
}
void Engine::PrimaryType::FGuid::DeSerializeField(std::istream& _is, const String& _fieldName)
{
	ValueType::DeSerializeField(_is, _fieldName);
}
#pragma endregion

