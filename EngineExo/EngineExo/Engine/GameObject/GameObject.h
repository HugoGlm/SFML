#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/List/List.h"
#include "../Component/Component.h"
#include <SFML/Graphics.hpp>

ENUM(PrimitiveType, Circle, Square)

namespace Engine
{
	UCLASS()
	class GameObject : public Object
	{
		DECLARE_CLASS_INFO(GameObject, Object)
#pragma region f/p
	private: 
		PrimaryType::List<Component*> components = PrimaryType::List<Engine::Component*>();
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
		void AddComponent(Component* _component);
		PrimaryType::List<Component*> Components() const;
		sf::Shape* Shape() const;
		void SetColor(const sf::Color& _color);
		static GameObject* CreatePrimitive(const PrimitiveType& _type, const PrimaryType::String& _name);
		template<typename T>
		T* AddComponent();
		template<typename T>
		T* GetComponent() const;
#pragma endregion
#pragma region operator
	public:
		GameObject& operator=(const GameObject& _other);
		PrimaryType::Boolean operator==(const GameObject& _other) const;
		PrimaryType::Boolean operator!=(const GameObject& _other) const;
#pragma endregion

	};
	template<typename T>
	T* GameObject::AddComponent()
	{
		static_assert(std::is_base_of_v<Component, T>, "T must be inherited of Component");
		T* _component = new T();
		_component->gameObject = this;
		components.Add(_component);
		return _component;
	}
	template<typename T>
	T* GameObject::GetComponent() const
	{
		const size_t _size = (size_t)components.Count();
		for (size_t i = 0; i < _size; ++i)
		{
			T* _result = dynamic_cast<T*>(components[i]);
			if (_result != nullptr)
				return _result;
		}
	}
}

