#include "FB_Game.h"
#include "../Menu/MainMenu/FB_MainMenu.h"
#include "../../UI/Button/FB_Button.h"
#include "../../UI/image/FB_Image.h"
#include "../Manager/FB_GameObjectManager.h"
#include "../Menu/GameOverMenu/FB_GameOverMenu.h"
#include "../Pipe/FB_Pipe.h"
#include "../Bird/FB_Bird.h"
#include "../Score/FB_Score.h"
#include "../DataBase/DataBase.h"
#include <iostream>

#pragma region constructor
FB_Game::FB_Game() : Window(900, 500, "Flappy Bird")
{
	InitBackGround();
	score = new FB_Score(this);
	score->SetPosition(sf::Vector2f(width / 2, 0));
}
FB_Game::~FB_Game()
{
	delete background;
	background = nullptr;
	delete score;
	score = nullptr;
}
#pragma endregion

#pragma region methods
void FB_Game::OnBirdDied()
{
	std::cout << "Bird is crendo !" << std::endl;
	isStarted = false;
	dynamic_cast<FB_GameOverMenu*>(menus[GAME_OVER_MENU])->SetScore(score->CurrentScore());
	OpenMenu(GAME_OVER_MENU);
}
void FB_Game::Start()
{
	score->Reset();
	FB_GameObjectManager::Instance()->DestroyAllObjects();
	CloseAllMenus();
	isStarted = true;
	bird = new FB_Bird();
	bird->SetWindowSize(sf::Vector2f(width, height));
	bird->OnDie.SetDynamic(this, &FB_Game::OnBirdDied);
	SpawnPipe();
	spawnerClock.restart();
}
void FB_Game::InitBackGround()
{
	background = new FB_Image(this, "C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/background_flappybird.png");
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetPosition(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(3.0f, 3.5f));
}
void FB_Game::SpawnPipe()
{
	FB_Pipe* _pipe = new FB_Pipe();
	FB_Pipe* _upPipe = new FB_Pipe();
	_pipe->onBirdPosition.SetDynamic(score, &FB_Score::UpdateScore);
	_upPipe->Rotate();

	int _random = rand() % 275 + 75;
	_pipe->SetPosition(sf::Vector2f(width + 100, _random + GAP));
	_upPipe->SetPosition(sf::Vector2f(width + 100 + _upPipe->GetGlobalBounds().width, _random));
}
#pragma endregion

#pragma region override
void FB_Game::OnDraw()
{
	background->Draw(this);
	for (std::pair<const char*, BaseMenu*> _pair : menus)
		_pair.second->Draw();
	if (!isStarted)
		return;
	FB_GameObjectManager::Instance()->Draw(this);
	score->Draw();
}
void FB_Game::OnUpdate()
{
	try
	{
		if (!isStarted)
			return;
		if (spawnerClock.getElapsedTime().asSeconds() >= TIME_FOR_SPAWN)
		{
			SpawnPipe();
			spawnerClock.restart();
		}
		FB_GameObjectManager* _instance = FB_GameObjectManager::Instance();
		_instance->CheckCollision();;
		_instance->Update();
		_instance->DestroyAllRequests();
	}
	catch (const std::exception& _e)
	{
		std::cout << _e.what() << std::endl;
	}
}
void FB_Game::InitMenus()
{
	FB_MainMenu* _mainMenu = new FB_MainMenu(this);
	_mainMenu->PlayButton()->OnClick.SetDynamic(this, &FB_Game::Start);
	_mainMenu->Open();
	RegisterMenu(MAIN_MENU, _mainMenu);

	FB_GameOverMenu* _gameOverMenu = new FB_GameOverMenu(this);
	_gameOverMenu->RestartButton()->OnClick.SetDynamic(this, &FB_Game::Start);
	RegisterMenu(GAME_OVER_MENU, _gameOverMenu);
}
void FB_Game::OnReceiveEvent(const sf::Event& _event)
{
	if (_event.type == sf::Event::Resized)
	{
		width = _event.size.width;
		height = _event.size.height;
		bird->SetWindowSize(sf::Vector2f(width, height));
	}
}
#pragma endregion

