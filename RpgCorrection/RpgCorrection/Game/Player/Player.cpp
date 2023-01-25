#include "Player.h"
#include "../../Core/Input/Input.h"
#include "../../Core/Time/Time.h"
#include "../Spell/FireBall/Spell/FireBallSpell.h"

#pragma region constructor
Game::Player::Player() : super("player")
{
	checkLow((sprite != nullptr), "[Player] => sprite is nullptr")
		SetOrigin(sf::Vector2f(0, 0));
	SetScale(sf::Vector2f(0.5f, 0.5f));
	stats.speed = 70.0f;
	spells.insert(std::pair(Core::EKey::R, new Spell::FireBallSpell(this)));
}
Game::Player::Player(const Player& _copy) : super(_copy)
{

}
Game::Player::~Player()
{

}
#pragma endregion

#pragma region override
void Game::Player::OnUpdate()
{
	super::OnUpdate();
	if (Core::Input::IsKey(Core::EKey::D))
		SetPosition(Position() + sf::Vector2f(1, 0) * stats.speed * Core::Time::deltaTime);
	if (Core::Input::IsKey(Core::EKey::Q))
		SetPosition(Position() - sf::Vector2f(1, 0) * stats.speed * Core::Time::deltaTime);
	if (Core::Input::IsKeyDown(Core::EKey::R))
		spells[Core::EKey::R]->OnUse();
}
void Game::Player::OnCollisionEnter(GameObject* _object)
{
	super::OnCollisionEnter(_object);
}
#pragma endregion