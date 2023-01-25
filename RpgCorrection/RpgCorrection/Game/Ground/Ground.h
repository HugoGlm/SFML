#pragma once
#include "../../Core/GameObject/GameObject.h"

namespace Game
{
	class Ground : public Core::GameObject
	{
		DECLARE_CLASS_INFO(Ground, GameObject)
#pragma region f/p
	private:
		sf::RectangleShape* rectShape = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Ground(const sf::Vector2f& _size, const sf::Color& _color);
#pragma endregion
#pragma region override
	public:
		void Draw(Core::Window* _window) override;
		void SetPosition(const sf::Vector2f& _position) override;
		void SetOrigin(const sf::Vector2f& _origin) override;
		void SetScale(const sf::Vector2f& _scale) override;
		sf::Vector2f Position() const;
		sf::Vector2f Origin() const override;
		sf::Vector2f Scale() const override;
		sf::FloatRect GlobalBounds() const override;
		bool IsValid() const override;
#pragma endregion

	};
}

