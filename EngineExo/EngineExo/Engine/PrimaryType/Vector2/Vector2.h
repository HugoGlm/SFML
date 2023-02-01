#pragma once
#include "../ValueType/ValueType.h"
#include "../Float/Float.h"
#include <SFML/Graphics.hpp>

namespace Engine::PrimaryType
{
    class Boolean;

    class Vector2 : public ValueType
    {
        DECLARE_CLASS_INFO(Vector2, ValueType)
#pragma region var
    public:
        Float x = 0.0f;
        Float y = 0.0f;
#pragma endregion
#pragma region const
    public:
        Vector2() = default;
        Vector2(const Vector2&) = default;
        Vector2(float _x, float _y);
#pragma region methods
    public:
        static Vector2 MoveToward(const Vector2& _current, const Vector2& _target, float _dt);
#pragma endregion
#pragma region override
    public:
        String ToString() const override;
        void SerializeField(std::ostream& _os, const String& _fieldName) override;
        void DeSerializeField(std::istream& _is, const String& _fieldName) override;
#pragma endregion
#pragma endregion
#pragma region operator
    public:
        operator sf::Vector2<float>() const;
        Object& operator=(const Object* _obj) override;

        Vector2& operator=(const Vector2& _vector2);
        Vector2& operator+=(const Vector2& _other);
        Vector2& operator-=(const Vector2& _other);
        Vector2& operator/=(const Vector2& _other);
        Vector2& operator*=(const Vector2& _other);

        Vector2 operator+(const Vector2& _vector2) const;
        Vector2 operator-(const Vector2& _vector2) const;
        Vector2 operator/(const Vector2& _vector2) const;
        Vector2 operator*(const Vector2& _vector2) const;

        Boolean operator==(const Vector2& _other) const;
        Boolean operator!=(const Vector2& _other) const;

        Float& operator[](size_t _index);
        Float operator[](size_t _index) const;
#pragma endregion

    };

}