#include "Object.h"
#include <typeinfo>

std::string Core::Object::ToString() const
{
	std::string _result = typeid(*this).name();
	return _result.substr(_result.find_last_of(' ') + 1);
}
