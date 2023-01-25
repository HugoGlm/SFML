#include "WindowMenu.h"
#include "../../../Input/Input.h"
#include "../../../Time/Time.h"
#include "../../../Event/Event.h"
#include "../Game/WindowGame.h"
#include <iostream>

#pragma region constructor
WindowMenu::WindowMenu()
{
	shapeBackground = new sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
	shapeStart = new sf::RectangleShape(sf::Vector2f(150, 100));
	shapeExit = new sf::RectangleShape(sf::Vector2f(150, 100));
	shapeBird = new sf::RectangleShape(sf::Vector2f(50, 50));
	bird = new sf::Texture();
	textureBackground = new sf::Texture();
	textureStart = new sf::Texture();
	textureExit = new sf::Texture();
	title = new sf::Text();
	fontTitle = new sf::Font();

	if (!bird->loadFromFile("../FP/flappy.png"))
		std::cout << "Error Flappy bird !" << std::endl;
	shapeBird->setTexture(bird);

	if (!textureBackground->loadFromFile("../Background/Background_Flappy_Bird.png"))
		std::cout << "Error Background !" << std::endl;
	shapeBackground->setTexture(textureBackground);

	if (!textureStart->loadFromFile("../Background/Bouton_Start.png"))
		std::cout << "Error Bouton Start !" << std::endl;
	shapeStart->setTexture(textureStart);

	if (!textureExit->loadFromFile("../Background/Bouton_Exit.png"))
		std::cout << "Error Bouton Exit !" << std::endl;
	shapeExit->setTexture(textureExit);

	if (!fontTitle->loadFromFile("../Fonts/FlappyBirdy.ttf"))
		std::cout << "Error title !" << std::endl;
	title->setFont(*fontTitle);
	title->setString("Flappy Bird");
	title->setCharacterSize(100);
}
WindowMenu::~WindowMenu()
{
	delete shapeBackground;
	shapeBackground = nullptr;
	delete	shapeStart;
	shapeStart = nullptr;
	delete	shapeExit;
	shapeExit = nullptr;
	delete	textureBackground;
	textureBackground = nullptr;
	delete	textureStart;
	textureStart = nullptr;
	delete textureExit;
	textureExit = nullptr;
	delete title;
	title = nullptr;
	delete fontTitle;
	fontTitle = nullptr;
	delete fontScore;
	fontScore = nullptr;
}
#pragma endregion

#pragma region override
void WindowMenu::OnDraw()
{
	Draw(shapeBackground);
	Draw(shapeStart);
	Draw(shapeExit);
	Draw(title);
	Draw(shapeBird);
}
void WindowMenu::OnUpdate()
{
	title->setPosition(300, 150);
	shapeBird->setPosition(400, 300);
	shapeStart->setPosition(250, 550);
	shapeExit->setPosition(550, 550);

	// Start
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
		if (shapeStart->getGlobalBounds().contains(sf::Vector2f(localPosition)))
		{
			Close();
			windowGame = new WindowGame();
			windowGame->Open();
		}
	}
	//Exit
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
		if (shapeExit->getGlobalBounds().contains(sf::Vector2f(localPosition)))
			Close();
	}
}
#pragma endregion
