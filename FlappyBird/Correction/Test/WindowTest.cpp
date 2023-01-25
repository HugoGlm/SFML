#include "WindowTest.h"
#include "../Input/Input.h"
#include "../Time/Time.h"
#include <iostream>

#pragma region constructor
WindowTest::WindowTest()
{
	shape = new sf::RectangleShape(sf::Vector2f(50, 50));
	text = new sf::Text();
	font = new sf::Font();
	if (!font->loadFromFile("../Fonts/Pokemon_Classic.ttf"))
		return;
	std::cout << "text valid !" << std::endl;
	text->setFont(*font);
	text->setString("Giratina sauvage apparaît !");
	text->setCharacterSize(24);
}
WindowTest::~WindowTest()
{
	delete shape;
	shape = nullptr;
	delete text;
	text = nullptr;
	delete font;
	font = nullptr;
}
#pragma endregion

#pragma region override
void WindowTest::OnDraw()
{
	//Draw(shape);
	Draw(text);
}
void WindowTest::OnUpdate()
{
	if (Input::IsKeyDown(sf::Keyboard::D))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(5, 0));
	}
	if (Input::IsKeyDown(sf::Keyboard::Q))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(-5, 0));
	}
	if (Input::IsKeyDown(sf::Keyboard::Z))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(0, -5));
	}
	if (Input::IsKeyDown(sf::Keyboard::S))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(0, 5));
	}
}
#pragma endregion
