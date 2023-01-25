#include "GameWindow.h"
#include "Menu/MainMenu.h"
#include "Menu/Game/GameMenu.h"

#pragma region constructor
Game::GameWindow::GameWindow() : super(900, 800, "RPG Game")
{
	MainMenu* _mainMenu = new MainMenu(this);
	_mainMenu->PlayButton()->OnClick.SetDynamic(this, &GameWindow::StartGame);
	RegisterMenu("main", _mainMenu); //TODO add to menu datatbase
	OpenMenu("main"); //TODO add to menu database
	GameMenu* _gameMenu = new GameMenu(this);
	RegisterMenu("game", _gameMenu); //TODO add to menu database
}
#pragma endregion

#pragma region methods
void Game::GameWindow::StartGame()
{
	OpenMenu("game"); //TODO add to menu database
}
#pragma endregion