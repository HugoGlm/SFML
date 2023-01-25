#pragma once
#include "../Window.h"
#include "../Game/WindowGame.h"
#include "../Menu/WindowMenu.h"

class WindowScore : public Window
{
#pragma region f/p
private:
	sf::RectangleShape* shapeBackground = nullptr;
	sf::Texture* textureBackground = nullptr;
	sf::RectangleShape* shapeReplay = nullptr;
	sf::RectangleShape* shapeScoreBoard = nullptr;
	sf::RectangleShape* shapeMenu = nullptr;
	sf::Texture* textureReplay = nullptr;
	sf::Texture* textureScoreBoard = nullptr;
	sf::Texture* textureMenu = nullptr;
	sf::Text* showScore = nullptr;
	sf::Text* gameOver = nullptr;
	sf::Font* fontScore = nullptr;
	sf::Font* fontGameOver = nullptr;

	WindowMenu* windowMenu = nullptr;
	WindowGame* windowGame = nullptr;
#pragma endregion
#pragma region constructor
public:
	WindowScore();
	~WindowScore() override;
#pragma endregion
#pragma region override
public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion

};

