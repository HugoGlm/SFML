#include "FireBallSpell.h"
#include "../FireBall.h"
#include "../../../Entity/Entity.h"

#pragma region constructor
Game::Spell::FireBallSpell::FireBallSpell(Entity::Entity* _entity) : super("fireball")
{
	owner = _entity;
}
#pragma endregion

#pragma region override
void Game::Spell::FireBallSpell::OnUse()
{
	FireBall* _fireBall = new FireBall(owner);
	_fireBall->SetPosition(owner->Position() + sf::Vector2f(_fireBall->GlobalBounds().width, 0));
}
#pragma endregion

