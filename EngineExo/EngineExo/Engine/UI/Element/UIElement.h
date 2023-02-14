#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Engine::PrimaryType
{
	class Vector2;
	class String;
}
namespace Engine::UI
{
	class UIElement : public Object
	{
		DECLARE_CLASS_INFO(UIElement, Object)
#pragma region f/p
	protected:
		sf::Shape* shape = nullptr;
		sf::Text labelText = sf::Text();
		bool canInteract = true;
		bool isActive = true;
#pragma endregion
#pragma region constructor
	public:
		UIElement();
		UIElement(const char* _label);
		virtual ~UIElement() override;
#pragma endregion
#pragma region methods
	public:
		virtual void SetPosition(const PrimaryType::Vector2& _position);
		virtual void SetRotation(float _angle);
		virtual void SetOrigin(const PrimaryType::Vector2& _origin);
		virtual void SetScale(const PrimaryType::Vector2& _scale);
		virtual void SetIsActive(bool _status);
		virtual void SetCanInteract(bool _status);
		virtual void SetLabel(const char* _label);
		virtual bool CanInteract() const;
		virtual bool IsActive() const;
		virtual sf::Shape* Shape() const;
		virtual PrimaryType::Vector2 Position() const;
		virtual float Rotation() const;
		virtual PrimaryType::Vector2 Scale() const;
		virtual PrimaryType::Vector2 Origin() const;
		virtual PrimaryType::String Label() const;
		virtual void Draw(sf::RenderWindow* _window);
#pragma endregion
#pragma region operator
	public:
		Object& operator=(const Object* _obj) override;
#pragma endregion

	};
}
