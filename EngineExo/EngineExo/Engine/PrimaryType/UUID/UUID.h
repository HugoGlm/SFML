#pragma once
#include "../ValueType/ValueType.h"
#include "../String/String.h"

namespace Engine::PrimaryType
{
	class FGuid : public ValueType
	{
		DECLARE_CLASS_INFO(FGuid, ValueType)
#pragma region f/p
	private:
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
#pragma endregion
#pragma region constructor
	public:
		FGuid() = default;
		FGuid(int _a, int _b, int _c, int _d);
#pragma endregion
#pragma region Methods
	public:
		FGuid NewGuid();
#pragma endregion
#pragma region override
	public:
		String ToString() const override;
		void SerializeField(std::ostream& _os, const String& _fieldName, int _index) override;
		void DeSerializeField(std::istream& _is, const String& _fieldName) override;
#pragma endregion


	};
}

