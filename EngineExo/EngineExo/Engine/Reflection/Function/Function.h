#pragma once
#include <string>
#include <vector>

namespace Engine
{
	namespace PrimaryType
	{
		class String;
	}
}

namespace Engine::Reflection
{
	class ParameterInfo;

	class Function
	{
#pragma region f/p
	private:
		std::string name = "";
		std::vector<ParameterInfo*> parameters = std::vector<ParameterInfo*>();
#pragma endregion
#pragma region constructor
	public:
		Function() = default;
		Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters);
		virtual ~Function() = default;
#pragma endregion
#pragma region methods
	public:
		PrimaryType::String Name() const;
		std::vector<ParameterInfo*> Parameters() const;
#pragma endregion

	};
}

