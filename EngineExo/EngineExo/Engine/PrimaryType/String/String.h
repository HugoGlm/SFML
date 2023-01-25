#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Boolean;
	UCLASS();
	class String : public ValueType
	{
		DECLARE_CLASS_INFO(String, ValueType)
#pragma region f/p
	private:
		const char* value = nullptr;
		int length = 0;
#pragma endregion
#pragma region constructor
	public:
		String() = default;
		String(const char* _value);
		String(const String& _copy);
#pragma endregion
#pragma region methods
	public:
		Boolean StartWith(char _c) const;
		Boolean EndWith(char _c) const;
		Boolean StartWith(const String& _str) const;
		Boolean EndWith(const String& _str) const;
		Boolean EqualsIgnoreCase(const String& _str) const;
		Boolean Contains(const String& _str) const;
		static Boolean IsNulOrEmpty(const String& _str);
		String ToLower() const;
		String ToUpper() const;
		String SubString(int _begin) const;
		String SubString(int _begin, int _end) const;
		String Replace(const String& _old, const String& _new) const;
		String Replace(char _old, char _new);
		String Trim() const;
		int FindFirstOf(char _c); //TODO replace int width Integer class
		int FindLastOf(char _c); //TODO replace int width Integer class
		size_t Length() const; //TODO replace int width Integer class
		void Append(const char* _str);
		void Append(const String& _str);
		String ToString() const override;
		const char* ToCstr() const;
#pragma endregion
#pragma region operator
	public:
		Object& operator=(const Object* _other);
		String& operator=(const String& _other);
		operator const char* ();
		operator const char* () const;
		Boolean operator==(const String& _str);
		Boolean operator!=(const String& _str);
#pragma endregion

	};
}

