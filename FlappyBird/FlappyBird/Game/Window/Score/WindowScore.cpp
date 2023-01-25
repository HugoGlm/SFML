#include "WindowScore.h"
#include "../../../Input/Input.h"
#include "../../../Time/Time.h"
#include "../../../Event/Event.h"
#include <iostream>

#pragma region constructor

WindowScore::WindowScore()
{
	shapeBackground = new sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
	shapeReplay = new sf::RectangleShape(sf::Vector2f(150, 100));
	shapeScoreBoard = new sf::RectangleShape(sf::Vector2f(150, 100));
	shapeMenu = new sf::RectangleShape(sf::Vector2f(100, 50));
	textureBackground = new sf::Texture();
	textureReplay = new sf::Texture();
	textureMenu = new sf::Texture();
	textureScoreBoard = new sf::Texture();
	gameOver = new sf::Text();
	showScore = new sf::Text();
	fontGameOver = new sf::Font();
	fontScore = new sf::Font();

	if (!textureBackground->loadFromFile("../Background/Background_Flappy_Bird.png"))
		std::cout << "Error Background !" << std::endl;
	shapeBackground->setTexture(textureBackground);

	if (!textureReplay->loadFromFile("../Background/Bouton_Start.png"))
		std::cout << "Error Bouton Replay !" << std::endl;
	shapeReplay->setTexture(textureReplay);

	if (!textureScoreBoard->loadFromFile("../Background/Bouton_ScoreBoard.png"))
		std::cout << "Error Bouton Replay !" << std::endl;
	shapeScoreBoard->setTexture(textureScoreBoard);

	if (!textureMenu->loadFromFile("../Background/Bouton_Menu.png"))
		std::cout << "Error Bouton Menu !" << std::endl;
	shapeMenu->setTexture(textureMenu);

	if (!fontGameOver->loadFromFile("../Fonts/FlappyBirdy.ttf"))
		std::cout << "Error title !" << std::endl;
	gameOver->setFont(*fontGameOver);
	gameOver->setString("Game Over");
	gameOver->setCharacterSize(150);
	gameOver->setFillColor(sf::Color::Yellow);

	if (!fontScore->loadFromFile("../Fonts/Pokemon_Classic.ttf"))
		std::cout << "Error title !" << std::endl;
	showScore->setFont(*fontScore);
	showScore->setString("0");
	showScore->setCharacterSize(50);
}
WindowScore::~WindowScore()
{
	delete shapeBackground;
	shapeBackground = nullptr;
	delete shapeReplay;
	shapeReplay = nullptr;
	delete shapeScoreBoard;
	shapeScoreBoard = nullptr;
	delete textureBackground;
	textureBackground = nullptr;
	delete textureReplay;
	textureReplay = nullptr;
	delete textureScoreBoard;
	textureScoreBoard = nullptr;
	delete gameOver;
	gameOver = nullptr;
	delete showScore;
	showScore = nullptr;
	delete fontGameOver;
	fontGameOver = nullptr;
	delete fontScore;
	fontScore = nullptr;
}
#pragma endregion

#pragma region override
void WindowScore::OnDraw()
{
	Draw(shapeBackground);
	Draw(gameOver);
	Draw(shapeReplay);
	Draw(shapeScoreBoard);
	Draw(shapeMenu);
	Draw(showScore);
}
void WindowScore::OnUpdate()
{
	showScore->setPosition(600, 400);
	gameOver->setPosition(250, 150);
	shapeReplay->setPosition(250, 550);
	shapeScoreBoard->setPosition(550, 550);
	shapeMenu->setPosition(425, 700);

	// Replay
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
		if (shapeReplay->getGlobalBounds().contains(sf::Vector2f(localPosition)))
		{
			Close();
			windowGame = new WindowGame();
			windowGame->Open();
		}
	}
	// ScoreBoard
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
		if (shapeScoreBoard->getGlobalBounds().contains(sf::Vector2f(localPosition)))
			std::cout << "ScoreBoard" << std::endl;
	}
	// Menu
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
		if (shapeMenu->getGlobalBounds().contains(sf::Vector2f(localPosition)))
		{
			Close();
			windowMenu = new WindowMenu();
			windowMenu->Open();
		}
	}
}
#pragma endregion
