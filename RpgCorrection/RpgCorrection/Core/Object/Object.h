#pragma once
#include <string>

#define DECLARE_CLASS_INFO(current, parent) \
	public:\
		typedef current self;\
		typedef parent super;

namespace Core
{
	class Object
	{
	public:
		Object() = default;
		Object(const Object&) = default;
		virtual ~Object() = default;
	public:
		virtual std::string ToString() const;
	};
}

