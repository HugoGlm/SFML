#include "Window.h"
#include "../Input/Input.h"
#include "../Time/Time.h"
#include "../GamePad/GamePad.h"
#include <iostream>
#include <conio.h>
#include <format>

int GetCH()
{
	if (_kbhit()) // retourne true si une touche est appuyé
	{
		return _getch(); // renvoie la touche appuyé
	}
	return -1;
}

#pragma region constructor
Window::Window()
{
	background = new sf::Sprite();
	textureBackground = new sf::Texture();
	perso = new sf::Sprite();
	texturePerso = new sf::Texture();
	textureCrouch = new sf::Texture();

	textureBackground->loadFromFile("../Textures/background.png");
	texturePerso->loadFromFile("../Textures/perso.png");
	textureCrouch->loadFromFile("../Textures/crouch.png");

	background->setTexture(*textureBackground);
	background->setPosition(0, 0);
	background->setScale(2.3f, 2.1f);

	perso->setTexture(*texturePerso);
	perso->setPosition(0 + 20, 1080 - 170);
	perso->setScale(1, 1);
	perso->setOrigin(0, 1);
}
Window::~Window()
{
	delete background;
	background = nullptr;
	delete textureBackground;
	textureBackground = nullptr;
	delete perso;
	perso = nullptr;
	delete texturePerso;
	texturePerso = nullptr;
	delete textureCrouch;
	textureCrouch = nullptr;
}
#pragma endregion

#pragma region override
void Window::OnDraw()
{
	Draw(background);
	Draw(perso);
}
void Window::OnUpdate()
{
	perso->setTexture(*texturePerso);
	sf::Joystick* _joystick = new sf::Joystick();
	if (isConnected == 0)
	{
		if (_joystick->isConnected(0))
			std::cout << "connected" << std::endl;
		isConnected++;
	}
	/*if (sf::Joystick::isButtonPressed(0, 0))
		std::cout << "A" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 1))
		std::cout << "B" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 2))
		std::cout << "Y" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 3))
		std::cout << "X" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 4))
		std::cout << "LB" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 5))
		std::cout << "LR" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 6))
		std::cout << "Share" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 7))
		std::cout << "Option" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 8))
		std::cout << "Joystick Left" << std::endl;
	else if (sf::Joystick::isButtonPressed(0, 9))
		std::cout << "Joystick Right" << std::endl;*/

	float X = _joystick->getAxisPosition(0, sf::Joystick::X);
	float Y = _joystick->getAxisPosition(0, sf::Joystick::Y);
	float U = _joystick->getAxisPosition(0, sf::Joystick::U);
	float V = _joystick->getAxisPosition(0, sf::Joystick::V);
	float Z = _joystick->getAxisPosition(0, sf::Joystick::Z);

	perso->setPosition(sf::Vector2f(perso->getPosition().x + (X / 1000), (perso->getPosition().y)));

	if (sf::Joystick::isButtonPressed(0, 0))
		perso->setPosition(perso->getPosition().x, (perso->getPosition().y - 0.5f));
	if (sf::Joystick::isButtonPressed(0, 1))
		perso->setTexture(*textureCrouch);
	perso->setPosition(perso->getPosition().x, (perso->getPosition().y + 0.3f));
	if (perso->getPosition().y > 1080 - 170)
		perso->setPosition(perso->getPosition().x, 1080 - 170);
}
#pragma endregion
