#include "EngineWindow.h"
#include "../../Time/Time.h"
#include "../../Event/Event.h"

#pragma region constructor
EngineWindow::EngineWindow(const float _width, const float _height, const char* _title)
{
	width = _width;
	height = _height;
	title = title;
}
EngineWindow::~EngineWindow()
{
	Close();
	delete window;
}
#pragma endregion

#pragma region methods
void EngineWindow::Update()
{
	sf::Event _event = sf::Event();
	sf::Clock _clock = sf::Clock();
	while (window->isOpen())
	{
		Time::deltaTime = _clock.restart().asSeconds();
		while (window->pollEvent(_event))
		{
			if (!window->hasFocus() && !eventIfNotFocus)
				continue;
			Event::currentEvent = &_event;
			OnReceiveEvent(_event);
			break;
		}
		OnUpdate();
		window->clear();
		OnDraw();
		window->display();
	}
}
void EngineWindow::Open()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	Update();
}
void EngineWindow::Close()
{
	if (!window->isOpen())
		return;
	window->close();
}
bool EngineWindow::IsOpen()
{
	return window->isOpen();
}
bool EngineWindow::HasFocus()
{
	return window->hasFocus();;
}
void EngineWindow::SetFrameLimit(const int _frame)
{
	window->setFramerateLimit(_frame);
}
void EngineWindow::Draw(sf::Drawable* _drawable)
{
	window->draw(*_drawable);
}
void EngineWindow::OnReceiveEvent(const sf::Event& _event)
{
	if (_event.type == sf::Event::Closed)
		Close();
}
#pragma endregion