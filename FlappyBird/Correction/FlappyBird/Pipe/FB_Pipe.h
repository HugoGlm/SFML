#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

#define PIPE_SPEED 250.0f
#define GAP 150.0f

class FB_Pipe : public GameObject
{
#pragma region f/p
private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	bool passedBird = false;
public:
	Delegate<void> onBirdPosition = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_Pipe();
	~FB_Pipe() override;
#pragma endregion
#pragma region methods
public:
	void Rotate();
	void Move();
	void SetPosition(const sf::Vector2f& _position);
#pragma endregion
#pragma region override
public:
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
	virtual void OnUpdate() override;
#pragma endregion


};

