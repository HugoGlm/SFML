#pragma once
#include "../Object/Object.h"

namespace Core
{
	class Time : public Object
	{
		DECLARE_CLASS_INFO(Time, Object)
	public:
		static inline float deltaTime = 0.0f;
	};
}