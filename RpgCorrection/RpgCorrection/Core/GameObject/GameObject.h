#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Core
{
	class GameObject : public Object
	{
		DECLARE_CLASS_INFO(GameObject, Object)
#pragma region f/p
	protected:
		sf::Sprite* sprite = nullptr;
	private:
		sf::RectangleShape* debugShape = nullptr;
		bool canDebug = false;
		std::vector<GameObject*> collidedObject = std::vector<GameObject*>();
#pragma endregion
#pragma region constructor
	public:
		GameObject();
		GameObject(const GameObject& _copy);
		~GameObject() override;
#pragma endregion
#pragma region methods
	public:
		static void Destroy(GameObject* _object);
		std::vector<GameObject*>& CollidedObject();
		void SetCanDebug(bool _status);
		virtual void SetPosition(const sf::Vector2f& _position);
		virtual void SetOrigin(const sf::Vector2f& _origin);
		virtual sf::Vector2f Position();
		virtual sf::Vector2f Origin() const;
		virtual bool IsValid() const;
		virtual void Draw(class Window* _window);
		virtual void OnUpdate();
		virtual void OnCollisionEnter(GameObject* _object);
		virtual void OnCollisionExit(GameObject* _object);
		virtual void SetScale(const sf::Vector2f& _scale);
		virtual sf::Vector2f Scale() const;
		virtual sf::FloatRect GlobalBounds() const;
#pragma endregion


	};
}

