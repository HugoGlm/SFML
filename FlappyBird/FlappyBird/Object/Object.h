#pragma once
#include <string>

class Object
{
#pragma region constructor
public:
	Object() = default;
	Object(const Object& _copy) = default;
	virtual ~Object() = default;
#pragma endregion
#pragma region methods
public:
	std::string ToString() const;
#pragma endregion

};

