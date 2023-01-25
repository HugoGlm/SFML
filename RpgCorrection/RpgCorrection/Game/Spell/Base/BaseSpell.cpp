#include "BaseSpell.h"
#include "../../Entity/Entity.h"

#pragma region constructor
Game::Spell::BaseSpell::BaseSpell(const char* _name)
{
    name = _name;
}
#pragma endregion

#pragma region methods
float Game::Spell::BaseSpell::Cooldown() const
{
    return cooldown;
}
float Game::Spell::BaseSpell::ManaCost() const
{
    return manaCost;
}
bool Game::Spell::BaseSpell::IsInCooldown() const
{
    return currentCooldown > 0.0f;
}
std::string Game::Spell::BaseSpell::Name() const
{
    return name;
}
Game::Entity::Entity* Game::Spell::BaseSpell::Owner() const
{
    return owner;
}
#pragma endregion

