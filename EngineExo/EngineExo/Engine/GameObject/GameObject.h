#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"
#include <SFML/Graphics.hpp>

ENUM(PrimitiveType, Circle, Square)

namespace Engine
{
	UCLASS()
	class GameObject : public Object
	{
		DECLARE_CLASS_INFO(GameObject, Object)
#pragma region f/p
	protected:
		sf::Shape* shape = nullptr;
		PrimaryType::String name = "";
#pragma endregion
#pragma region constructor
	public:
		GameObject() = default;
		GameObject(const PrimaryType::String& _name);
		GameObject(const GameObject& _copy);
		~GameObject() override;
#pragma endregion
#pragma region methods
	public:
		sf::Shape* Shape() const;
		void SetColor(const sf::Color& _color);
		static GameObject* CreatePrimitive(const PrimitiveType& _type, const PrimaryType::String& _name);
#pragma endregion
#pragma region operator
	public:
		GameObject& operator=(const GameObject& _other);
		PrimaryType::Boolean operator==(const GameObject& _other) const;
		PrimaryType::Boolean operator!=(const GameObject& _other) const;
#pragma endregion

	};
}

