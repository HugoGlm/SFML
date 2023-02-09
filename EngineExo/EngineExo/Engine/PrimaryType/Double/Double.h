#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Double : public ValueType
	{
		DECLARE_CLASS_INFO(Double, ValueType)
#pragma region f/p
	private:
		double value = -1.0f;
	public:
		static const Double Epsilon;
		static const Double MinValue;
		static const Double MaxValue;
		static const Double PositiveInfinity;
		static const Double NegativeInfinity;
		static const Double NaN;
#pragma endregion
#pragma region constructor
	public:
		Double() = default;
		Double(double _value);
#pragma endregion
#pragma region methods
	public:
		static Double Parse(const String& _str);
		static class Boolean TryParse(const String& _str, Double& _output);
		static Boolean IsNaN(const Double& _value);
		static Boolean IsEpsilon(const Double& _value);
		static Boolean IsPositiveInfinity(const Double& _value);
		static Boolean IsNegativeInfinity(const Double& _value);
#pragma endregion
#pragma region override
	public:
		String ToString() const override;
		void SerializeField(std::ostream& _os, const String& _fieldName, int _index) override;
		void DeSerializeField(std::istream& _is, const String& _fieldName) override;
#pragma endregion
#pragma region operator
	public:
		Double& operator=(const Double& _other);
		operator double();
		operator double() const;

		Double operator+(double _other) const;
		Double operator-(double _other) const;
		Double operator*(double _other) const;
		Double operator/(double _other) const;
		Double operator-() const;

		Double& operator+=(double _other);
		Double& operator-=(double _other);
		Double& operator*=(double _other);
		Double& operator/=(double _other);

		Boolean operator<(double _other) const;
		Boolean operator<=(double _other) const;
		Boolean operator>(double _other) const;
		Boolean operator>=(double _other) const;
		Boolean operator==(double _other) const;
		Boolean operator!=(double _other) const;
#pragma endregion

	};
}

