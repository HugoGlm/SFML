#pragma once
#include "../../../Object/Object.h"
#include <string>

namespace Engine::Reflection
{
	struct ParameterInfo : public Object
	{
#pragma region f/p
	private:
		std::string name = "";
		int position = 0;
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
		int Position() const;
#pragma endregion
#pragma region override
	public:
		PrimaryType::String ToString() const override;
#pragma endregion

	};
}