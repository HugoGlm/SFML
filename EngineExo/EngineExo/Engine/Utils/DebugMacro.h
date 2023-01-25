#pragma once
#include "../Exception/Exception.h"
#include "../Utils/Console/Console.h"

#define checkLow(condition, msg)\
	if (!condition)\
	{\
		LOG_ERROR(msg);\
		return;\
	}

#define check(condition, msg, result)\
	if (!condition)\
	{\
		LOG_ERROR(msg);\
		return result;\
	}

#define checkBaseOf(a, b)\
	if constexpr (std::is_base_of_v<a, b>)\
	{\
		LOG_ERROR(#b " must be inherited of " #a);\
		return;\
	}

#define LOG(msg) Engine::Utils::Console::Log(msg);
#define LOG_WARNING(msg) Engine::Utils::Console::LogWarning(msg);
#define LOG_ERROR(msg) Engine::Utils::Console::LogError(msg);