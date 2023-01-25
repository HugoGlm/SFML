#include "FB_GameOverMenu.h"
#include "../../../Window/Window.h"
#include "../../../UI/image/FB_Image.h"
#include "../../../UI/Button/FB_Button.h"
#include "../../../UI/Label/FB_Label.h"

#pragma region constructor
FB_GameOverMenu::FB_GameOverMenu(Window* _owner) : BaseMenu(_owner)
{
	const float _centerWidth = _owner->Width() / 2;
	const float _centerHeight = _owner->Height() / 2;

	InitGameOverImage(_owner, _centerWidth, _centerHeight);
	InitTitleImage(_owner, _centerWidth);
	InitRestartButton(_centerWidth, _centerHeight);
	InitScoreText(_centerWidth, _centerHeight);
}
FB_GameOverMenu::~FB_GameOverMenu()
{
	delete gameOverImage;
	gameOverImage = nullptr;
	delete titleImage;
	titleImage = nullptr;
	delete restartButton;
	restartButton = nullptr;
}
#pragma endregion

#pragma region methods
void FB_GameOverMenu::InitRestartButton(const float& _centerWidth, const float& _centerHeight)
{
	restartButton = new FB_Button(owner, "C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/flappybird_play_button.png");
	restartButton->SetScale(sf::Vector2f(0.3f, 0.3f));
	restartButton->SetPosition(sf::Vector2f(_centerWidth - (restartButton->GetGlobalBounds().width + 100), _centerHeight));
	elements.push_back(restartButton);
}
void FB_GameOverMenu::InitTitleImage(Window* _owner, const float& _centerWidth)
{
	titleImage = new FB_Image(_owner, "C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/Flappy_Logo.png");
	titleImage->SetPosition(sf::Vector2f(_centerWidth - 150, 20));
	titleImage->SetScale(sf::Vector2f(0.1f, 0.1f));
	titleImage->SetOrigin(sf::Vector2f(titleImage->GetGlobalBounds().width / 2, titleImage->GetGlobalBounds().height / 2));
	elements.push_back(titleImage);
}
void FB_GameOverMenu::InitGameOverImage(Window* _owner, const float& _centerWidth, const float& _centerHeight)
{
	gameOverImage = new FB_Image(_owner, "C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/flappyBirdGameOver.png");
	gameOverImage->SetScale(sf::Vector2f(0.2f, 0.2f));
	sf::Vector2f _position = sf::Vector2f(_centerWidth - (gameOverImage->GetGlobalBounds().width / 2), _centerHeight - (gameOverImage->GetGlobalBounds().height * 2));
	gameOverImage->SetPosition(_position);
	elements.push_back(gameOverImage);
}
void FB_GameOverMenu::InitScoreText(const float& _centerWidth, const float& _centerHeight)
{
	scoreText = new FB_Label(owner, "0");
	scoreText->SetColor(sf::Color::Black);
	scoreText->SetPosition(sf::Vector2f(_centerWidth - (gameOverImage->GetGlobalBounds().width / 2), _centerHeight - (gameOverImage->GetGlobalBounds().height * 2) + 50));
	elements.push_back(scoreText);
}
FB_Button* FB_GameOverMenu::RestartButton()
{
	return restartButton;
}
void FB_GameOverMenu::SetScore(const int _score)
{
	scoreText->SetText(("Score: " + std::to_string(_score)).c_str());
}
#pragma endregion

#pragma region override
void FB_GameOverMenu::Draw()
{
	BaseMenu::Draw();
}
#pragma endregion

