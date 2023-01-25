#include "FireBall.h"
#include "../../../Core/Environment/Environment.h"
#include "../../../Core/Utils/Debug/Debug.h"
#include "../../../Core/Utils/Path/Path.h"
#include "../../../Core/Time/Time.h"

#pragma region constructor
Game::Spell::FireBall::FireBall(Entity::Entity* _owner) : super()
{
	owner = _owner;
	sprite = new sf::Sprite();
	sprite->setScale(0.5f, 0.5f);
	gif = new Core::Gif(Core::Utils::Path::Combine({ Core::Environment::AssetPath, "Spell", "direballspell.gif" }).c_str());
}
Game::Spell::FireBall::~FireBall()
{
	delete gif;
	gif = nullptr;
}
#pragma endregion

#pragma region methods
void Game::Spell::FireBall::SetDirection(const sf::Vector2f& _direction)
{
	direction = _direction;
}
void Game::Spell::FireBall::SetDamage(const float _dmg)
{
	damage = _dmg;
}
#pragma endregion

#pragma region override
void Game::Spell::FireBall::OnUpdate()
{
	checkLow((gif != nullptr && sprite != nullptr), "[FireBall] => gif or sprite is nullptr")
		SetPosition(Position() + direction * speed * Core::Time::deltaTime);
	gif->update(*sprite);
	if (clock.getElapsedTime().asSeconds() > lifeTime)
		Destroy(this);
}
void Game::Spell::FireBall::OnCollisionEnter(GameObject* _object)
{
	Entity::Entity* _other = dynamic_cast<Entity::Entity*>(_object);
	if (_other == nullptr || _other == owner)
		return;
	_other->TakeDamage(10.0f); //TODO damage of spell.
	Destroy(this);
}
#pragma endregion

