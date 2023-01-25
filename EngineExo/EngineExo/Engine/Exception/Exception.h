#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"
#include <source_location>

namespace Engine
{
	class Exception : public Object
	{
		DECLARE_CLASS_INFO(Exception, Object)
#pragma region f/p
			PrimaryType::String message = "";
#pragma endregion
#pragma region constructor
	public:
		Exception(const std::source_location& _source);
		Exception(const char* _error, const std::source_location& _source);
		Exception(const Exception& _copy);
#pragma endregion
#pragma region methods
	public:
		PrimaryType::String Error() const;
#pragma endregion
#pragma region override
	public:
		PrimaryType::String ToString() const override;
#pragma endregion

	};
}

