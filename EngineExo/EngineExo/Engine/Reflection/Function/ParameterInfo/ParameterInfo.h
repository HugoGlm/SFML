#pragma once
#include "../../../Utils/Interface/Log/ILogger.h"
#include <string>

namespace Engine::Reflection
{
	class ParameterInfo : public Interface::ILogger
	{
#pragma region f/p
	private:
		std::string name = "";
		size_t position = 0;
#pragma endregion
#pragma region constructor
	public:
		ParameterInfo() = default;
		ParameterInfo(const std::string& _name, int _position);
		~ParameterInfo() = default;
#pragma endregion
#pragma region methods
	public:
		std::string Name() const;
		size_t Position() const;
#pragma endregion
#pragma region override
	public:
		PrimaryType::String ToString() const override;
#pragma endregion

	};
}