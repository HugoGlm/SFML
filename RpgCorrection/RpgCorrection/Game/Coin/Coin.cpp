#include "Coin.h"
#include "../../Core/Environment/Environment.h"
#include "../../Core/Utils/Path/Path.h"
#include "../Player/Player.h"

#pragma region constructor
Game::Coin::Coin() : super()
{
	sprite = new sf::Sprite();
	gif = new Core::Gif(Core::Utils::Path::Combine({ Core::Environment::AssetPath, "Coin", "Coin.gif" }).c_str());
	SetOrigin(sf::Vector2f(GlobalBounds().width / 2, GlobalBounds().height / 2));
	SetScale(sf::Vector2f(0.3f, 0.3f));
}
Game::Coin::~Coin()
{
	delete gif;
	gif = nullptr;
}
#pragma endregion

#pragma region methods
void Game::Coin::OnUpdate()
{
	gif->update(*sprite);
}
void Game::Coin::OnCollisionEnter(GameObject* _object)
{
	Player* _player = dynamic_cast<Player*>(_object);
	if (_player == nullptr)
		return;
	//TODO add coin to player inventory
	Destroy(this);
}
#pragma region

