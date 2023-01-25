#include "WindowGame.h"
#include "../../../Input/Input.h"
#include "../../../Time/Time.h"
#include "../../../Event/Event.h"
#include "../Score/WindowScore.h"
#include <iostream>

#pragma region constructor

WindowGame::WindowGame()
{
	shapeBackground = new sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
	pipeUp = new sf::RectangleShape(sf::Vector2f(100, 300));
	pipeUpTwo = new sf::RectangleShape(sf::Vector2f(100, 300));
	pipeUpTree = new sf::RectangleShape(sf::Vector2f(100, 300));
	pipeDown = new sf::RectangleShape(sf::Vector2f(100, 300));
	pipeDownTwo = new sf::RectangleShape(sf::Vector2f(100, 300));
	pipeDownTree = new sf::RectangleShape(sf::Vector2f(100, 300));
	shapeBird = new sf::RectangleShape(sf::Vector2f(50, 50));
	textureBackground = new sf::Texture();
	pipeUpTexture = new sf::Texture();
	pipeUpTwoTexture = new sf::Texture();
	pipeUpTreeTexture = new sf::Texture();
	pipeDownTexture = new sf::Texture();
	pipeDownTwoTexture = new sf::Texture();
	pipeDownTreeTexture = new sf::Texture();
	bird = new sf::Texture();
	showScore = new sf::Text();
	fontScore = new sf::Font();

	if (!bird->loadFromFile("../FP/flappy.png"))
		std::cout << "Error Flappy bird !" << std::endl;
	shapeBird->setTexture(bird);
	shapeBird->setPosition(50, 250);

	if (!textureBackground->loadFromFile("../Background/Background_Flappy_Bird.png"))
		std::cout << "Error Background !" << std::endl;
	shapeBackground->setTexture(textureBackground);

	if (!pipeUpTexture->loadFromFile("../FP/pipes2.png"))
		std::cout << "Error pipeUp !" << std::endl;
	pipeUp->setTexture(pipeUpTexture);
	pipeUp->setPosition(300, 500);
	
	if (!pipeDownTexture->loadFromFile("../FP/pipes.png"))
		std::cout << "Error pipeDown !" << std::endl;
	pipeDown->setTexture(pipeDownTexture);
	pipeDown->setPosition(300, 0);

	if (!pipeUpTwoTexture->loadFromFile("../FP/pipes2.png"))
		std::cout << "Error pipeUp !" << std::endl;
	pipeUpTwo->setTexture(pipeUpTwoTexture);
	pipeUpTwo->setPosition(650, 500);

	if (!pipeDownTwoTexture->loadFromFile("../FP/pipes.png"))
		std::cout << "Error pipeDown !" << std::endl;
	pipeDownTwo->setTexture(pipeDownTwoTexture);
	pipeDownTwo->setPosition(650, 0);

	if (!pipeUpTreeTexture->loadFromFile("../FP/pipes2.png"))
		std::cout << "Error pipeUp !" << std::endl;
	pipeUpTree->setTexture(pipeUpTreeTexture);
	pipeUpTree->setPosition(1000, 500);

	if (!pipeDownTreeTexture->loadFromFile("../FP/pipes.png"))
		std::cout << "Error pipeDown !" << std::endl;
	pipeDownTree->setTexture(pipeDownTreeTexture);
	pipeDownTree->setPosition(1000, 0);

	if (!fontScore->loadFromFile("../Fonts/Pokemon_Classic.ttf"))
		std::cout << "Error title !" << std::endl;
	showScore->setFont(*fontScore);
	showScore->setString("0");
	showScore->setCharacterSize(50);
}
WindowGame::~WindowGame()
{
	delete shapeBackground;
	shapeBackground = nullptr;
	delete pipeUp;
	pipeUp = nullptr;
	delete pipeDown;
	pipeDown = nullptr;
	delete pipeUpTexture;
	pipeUpTexture = nullptr;
	delete pipeDownTexture;
	pipeDownTexture = nullptr;
	delete pipeUpTwo;
	pipeUpTwo = nullptr;
	delete pipeDownTwo;
	pipeDownTwo = nullptr;
	delete pipeUpTwoTexture;
	pipeUpTwoTexture = nullptr;
	delete pipeDownTwoTexture;
	pipeDownTwoTexture = nullptr;
	delete pipeUpTree;
	pipeUpTree = nullptr;
	delete pipeDownTree;
	pipeDownTree = nullptr;
	delete pipeUpTreeTexture;
	pipeUpTreeTexture = nullptr;
	delete pipeDownTreeTexture;
	pipeDownTreeTexture = nullptr;
	delete	shapeBird;
	shapeBird = nullptr;
	delete	textureBackground;
	textureBackground = nullptr;
	delete	bird;
	bird = nullptr;
	delete	showScore;
	showScore = nullptr;
	delete	fontScore;
	fontScore = nullptr;
}
#pragma endregion

#pragma region override
void WindowGame::OnDraw()
{
	Draw(shapeBackground);
	Draw(pipeUp);
	Draw(pipeDown);
	Draw(pipeUpTwo);
	Draw(pipeDownTwo);
	Draw(pipeUpTree);
	Draw(pipeDownTree);
	Draw(shapeBird);
	Draw(showScore);
}
void WindowGame::OnUpdate()
{
	showScore->setPosition(WIDTH / 2, 0);

#pragma region collision
	if (shapeBird->getPosition().y <= -35 || shapeBird->getPosition().y >= HEIGHT - 35)
	{
		Close();
		windowScore = new WindowScore();
		windowScore->Open();
	}
	if (shapeBird->getGlobalBounds().intersects(pipeDown->getGlobalBounds()) || 
		shapeBird->getGlobalBounds().intersects(pipeUp->getGlobalBounds()) ||
		shapeBird->getGlobalBounds().intersects(pipeDownTwo->getGlobalBounds()) ||
		shapeBird->getGlobalBounds().intersects(pipeUpTwo->getGlobalBounds()) ||
		shapeBird->getGlobalBounds().intersects(pipeDownTwo->getGlobalBounds()) ||
		shapeBird->getGlobalBounds().intersects(pipeUpTwo->getGlobalBounds()))
	{
		Close();
		windowScore = new WindowScore();
		windowScore->Open();
	}
#pragma endregion

#pragma region pipes
	// pipe one
	pipeUp->setPosition(pipeUp->getPosition() + sf::Vector2f(-0.10, 0));
	pipeDown->setPosition(pipeDown->getPosition() + sf::Vector2f(-0.10, 0));
	// pipe two
	pipeUpTwo->setPosition(pipeUpTwo->getPosition() + sf::Vector2f(-0.10, 0));
	pipeDownTwo->setPosition(pipeDownTwo->getPosition() + sf::Vector2f(-0.10, 0));
	// pipe tree
	pipeUpTree->setPosition(pipeUpTree->getPosition() + sf::Vector2f(-0.10, 0));
	pipeDownTree->setPosition(pipeDownTree->getPosition() + sf::Vector2f(-0.10, 0));

	int Range = -100;
	int reDrawPipe = WIDTH + 100;

	if (pipeUp->getPosition().x <= Range && pipeDown->getPosition().x <= Range)
	{
		pipeUp->setPosition(pipeUp->getPosition() + sf::Vector2f(reDrawPipe, 0));
		pipeDown->setPosition(pipeDown->getPosition() + sf::Vector2f(reDrawPipe, 0));
	}

	if (pipeUpTwo->getPosition().x <= Range && pipeDownTwo->getPosition().x <= Range)
	{
		pipeUpTwo->setPosition(pipeUpTwo->getPosition() + sf::Vector2f(reDrawPipe, 0));
		pipeDownTwo->setPosition(pipeDownTwo->getPosition() + sf::Vector2f(reDrawPipe, 0));
	}

	if (pipeUpTree->getPosition().x <= Range && pipeDownTree->getPosition().x <= Range)
	{
		pipeUpTree->setPosition(pipeUpTree->getPosition() + sf::Vector2f(reDrawPipe, 0));
		pipeDownTree->setPosition(pipeDownTree->getPosition() + sf::Vector2f(reDrawPipe, 0));
	}
#pragma endregion

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		shapeBird->setPosition(shapeBird->getPosition() + sf::Vector2f(0, -0.15));
	else
		shapeBird->setPosition(shapeBird->getPosition() + sf::Vector2f(0, 0.10));
}
#pragma endregion
