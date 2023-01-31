#include "PlayerComponent.h"
#include "../../Engine/GameObject/GameObject.h"
#include "../../Engine/Time/Time.h"

void Test::PlayerComponent::update()
{
	gameobject->transform->position = Engine::PrimaryType::Vector2::MoveToward(gameobject->transform->position, Engine::PrimaryType::Vector2(100, 0), Engine::Time::deltaTime * 10.0f);
}
