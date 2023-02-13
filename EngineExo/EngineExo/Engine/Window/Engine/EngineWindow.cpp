#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Time/Time.h"
#include "../../Utils/CoreDefine.h"
#include "../../UI/Manager/UIElementManager.h"
#include <format>
#include <iostream>

#pragma region constructor
Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
	UI::Label::Label* _toggle = new UI::Label::Label(this, sf::Vector2f(250, 250), "Toggle: ");
	button = new UI::Shape::Rectangle::RectangleShape(this, sf::Vector2f(30, 30), sf::Vector2f(400, 250));
	cross = new UI::Label::Label(this, sf::Vector2f(400, 250), "");
	cross->SetColor(sf::Color::Black);

	UI::Label::Label* _slider = new UI::Label::Label(this, sf::Vector2f(250, 350), "Slider: ");
	circleLine = new UI::Shape::Circle::CircleShape(this, 10.0f, sf::Vector2f(560, 360));
	UI::Label::Label* _min = new UI::Label::Label(this, sf::Vector2f(380, 350), "min");
	UI::Label::Label* _max = new UI::Label::Label(this, sf::Vector2f(680, 350), "max");
	line = new UI::Shape::Rectangle::RectangleShape(this, sf::Vector2f(200, 2), sf::Vector2f(460, 370));
	pourcentage = new UI::Label::Label(this, sf::Vector2f(780, 350), "");

	UI::Label::Label* _textField = new UI::Label::Label(this, sf::Vector2f(250, 450), "TextField: ");
	text = new UI::Shape::Rectangle::RectangleShape(this, sf::Vector2f(200, 20), sf::Vector2f(450, 460));

	UI::Label::Label* _label = new UI::Label::Label(this, sf::Vector2f(250, 550), "Label: ");

	UI::Manager::UIElementManager::Instance()->Register(_toggle);
	UI::Manager::UIElementManager::Instance()->Register(button);
	UI::Manager::UIElementManager::Instance()->Register(cross);

	UI::Manager::UIElementManager::Instance()->Register(_slider);
	UI::Manager::UIElementManager::Instance()->Register(line);
	UI::Manager::UIElementManager::Instance()->Register(circleLine);
	UI::Manager::UIElementManager::Instance()->Register(_min);
	UI::Manager::UIElementManager::Instance()->Register(pourcentage);

	UI::Manager::UIElementManager::Instance()->Register(_textField);
	UI::Manager::UIElementManager::Instance()->Register(text);

	UI::Manager::UIElementManager::Instance()->Register(_label);
}
Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
	: super(_copy.name, _copy.width, _copy.height) { }
#pragma endregion

#pragma region override
void Engine::Window::EngineWindow::Open()
{
	super::Open();
	SetFramesLimit(60);
}
void Engine::Window::EngineWindow::OnUpdate()
{
	Time::deltaTime = clock.restart().asSeconds();
	Manager::GameObjectManager::Instance()->Update();
	Clear();
	Manager::GameObjectManager::Instance()->Draw(this);
	UI::Manager::UIElementManager::Instance()->Draw(this);
	Display();
}
void Engine::Window::EngineWindow::OnClear() const
{
	super::OnClear();
}
void Engine::Window::EngineWindow::OnReceiveEvent(const sf::Event& _event)
{
	super::OnReceiveEvent(_event);
	if (button->GetGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (checked == true)
		{
			cross->SetText("");
			checked = false;
		}
		else if (checked == false)
		{
			cross->SetText("X");
			checked = true;
		}
	}
	if (circleLine->GetGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		size_t _sizeLine = 200;
		sf::Vector2f _positionLine = sf::Vector2f(460, 370);
		sf::Vector2f _positionCircle = sf::Vector2f(560, 360);

		if (sf::Event::MouseMoved)
		{
			if (sf::Mouse::getPosition().x < _positionLine.x)
				return;
			if (_positionCircle.x < _sizeLine + _positionLine.x && sf::Mouse::getPosition().x < _positionLine.x)
			{
				_positionCircle.x = sf::Mouse::getPosition().x;
				circleLine->SetPosition(sf::Vector2f(_positionCircle.x - 5.0f, _positionCircle.y));
			}
			if (_positionCircle.x = _sizeLine + _positionLine.x)
			{
				if (sf::Mouse::getPosition().x > _sizeLine + _positionLine.x)
					return;
				else
				{
					_positionCircle.x = sf::Mouse::getPosition().x;
					circleLine->SetPosition(sf::Vector2f(_positionCircle.x - 5.0f, _positionCircle.y));
				}
			}
		}
		pourcentage->SetText(std::format("{}", (_positionCircle.x - 460)/2));
	}
	if (text->GetGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		LOG("TEXT")
	}
}
#pragma endregion