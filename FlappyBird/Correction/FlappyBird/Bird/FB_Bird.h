#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

#define BIRD_SCALE 0.08f
#define GRAVITY 0.5f
#define BIRD_SPEED_GRAVITY 350
#define BIRD_JUMP_FORCE 40

class FB_Bird : public GameObject
{
#pragma region f/p
private:
	bool isDead = false;
	sf::Clock lastjumpTimer = sf::Clock();
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	sf::Vector2f windowSize = sf::Vector2f();
public:
	Delegate<void> OnDie = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_Bird();
	virtual ~FB_Bird() override;
#pragma endregion
#pragma region override
private:
	void Die();
public:
	virtual void OnUpdate() override;
	virtual void OnCollisionEnter(GameObject* _other);
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
	void SetWindowSize(const sf::Vector2f& _size);
#pragma endregion

};

