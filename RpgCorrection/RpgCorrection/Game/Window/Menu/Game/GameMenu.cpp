#include "GameMenu.h"
#include "../../../../Core/UI/Image/Image.h"
#include "../../../../Core/Window/Window.h"

#pragma region constructor
Game::GameMenu::GameMenu(Core::Window* _owner) : super(_owner)
{
	Init();
}
#pragma endregion

#pragma region methods
void Game::GameMenu::Init()
{
	background = CreateImage(sf::Vector2f(0, 0), BACKGROUND_GAME_PATH);
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(owner->Width() / background->GlobalBounds().width, owner->Height() / background->GlobalBounds().height));
}
#pragma endregion
#pragma region override
void Game::GameMenu::Open()
{
	super::Open();
	//test
	if (mob != nullptr)
		return;
	mob = new Entity::Mob("monster");
	mob->SetInitialPosition(sf::Vector2f(450, owner->Height() - (mob->GlobalBounds().height * 1.1f)));

	player = new Player();
	player->SetPosition(sf::Vector2f(0, owner->Height() - (player->GlobalBounds().height * 1.5f)));

	ground = new Ground(sf::Vector2f(background->GlobalBounds().width, 50), sf::Color::Transparent);
	ground->SetOrigin(sf::Vector2f(0, 0));
	ground->SetPosition(sf::Vector2f(0, owner->Height() - 90));
}
void Game::GameMenu::OnResize(const sf::Vector2f& _size)
{

}
#pragma endregion


