#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Time/Time.h"
#include "../../Utils/CoreDefine.h"
#include "../../UI/Manager/UIElementManager.h"
#include "../../UI/Shape/Circle/CircleShape.h"

#pragma region constructor
Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
	UI::Label::Label* _toggle = new UI::Label::Label(this, sf::Vector2f(250, 250), "Toggle: ");
	button = new UI::Shape::Rectangle::RectangleShape(this, sf::Vector2f(30, 30), sf::Vector2f(400, 250));
	cross = new UI::Label::Label(this, sf::Vector2f(400, 250), "X");
	cross->SetColor(sf::Color::Black);

	UI::Label::Label* _slider = new UI::Label::Label(this, sf::Vector2f(250, 350), "Slider: ");
	UI::Shape::Circle::CircleShape* _circleLine = new UI::Shape::Circle::CircleShape(this, 10.0f, sf::Vector2f(560, 360));
	UI::Label::Label* _min = new UI::Label::Label(this, sf::Vector2f(380, 350), "min");
	UI::Label::Label* _max = new UI::Label::Label(this, sf::Vector2f(680, 350), "max");
	UI::Shape::Rectangle::RectangleShape* _line = new UI::Shape::Rectangle::RectangleShape(this, sf::Vector2f(200, 2), sf::Vector2f(460, 370));

	UI::Label::Label* _textField = new UI::Label::Label(this, sf::Vector2f(250, 450), "TextField: ");
	UI::Shape::Rectangle::RectangleShape* _text = new UI::Shape::Rectangle::RectangleShape(this, sf::Vector2f(200, 20), sf::Vector2f(450, 460));

	UI::Label::Label* _label = new UI::Label::Label(this, sf::Vector2f(250, 550), "Label: ");

	UI::Manager::UIElementManager::Instance()->Register(_toggle);
	UI::Manager::UIElementManager::Instance()->Register(button);
	UI::Manager::UIElementManager::Instance()->Register(cross);

	UI::Manager::UIElementManager::Instance()->Register(_slider);
	UI::Manager::UIElementManager::Instance()->Register(_line);
	UI::Manager::UIElementManager::Instance()->Register(_circleLine);
	UI::Manager::UIElementManager::Instance()->Register(_min);
	UI::Manager::UIElementManager::Instance()->Register(_max);

	UI::Manager::UIElementManager::Instance()->Register(_textField);
	UI::Manager::UIElementManager::Instance()->Register(_text);

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
	//if (button->GetGlobalBounds().intersects(sf::Mouse::isButtonPressed)
}
#pragma endregion

