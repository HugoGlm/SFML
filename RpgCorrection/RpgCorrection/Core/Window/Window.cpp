#include "Window.h"
#include "../Input/Input.h"
#include "../Utils/Debug/Debug.h"
#include "Menu/BaseMenu.h"
#include "../Time/Time.h"
#include "../Manager/GameObjectManager/GameObjectManager.h"
#include <format>
#include <ranges>

#pragma region constructor
Core::Window::Window(int _width, int _height, const char* _title)
{
	width = _width;
	height = _height;
	title = _title;
}
Core::Window::~Window()
{
	Close();
	for (BaseMenu*& _menu : menus | std::ranges::views::values)
	{
		delete _menu;
		_menu = nullptr;
	}
	menus.clear();
	delete render;
	render = nullptr;
}
#pragma endregion


#pragma region methods
void Core::Window::Open()
{
	render = new sf::RenderWindow(sf::VideoMode(width, height), title);
	Update();
}
void Core::Window::Close()
{
	if (!render->isOpen())
		return;
	render->close();
}
void Core::Window::Update()
{
	while (render->isOpen())
	{
		Time::deltaTime = deltaClock.restart().asSeconds();
		while (render->pollEvent(currentEvent))
		{
			OnReceiveEvent(currentEvent);
		}
		OnUpdate();
		render->clear();
		OnDraw();
		render->display();
	}
}
int Core::Window::Width() const
{
	return width;
}
int Core::Window::Height() const
{
	return height;
}
sf::RenderWindow* Core::Window::Render() const
{
	return render;
}
void Core::Window::Draw(const sf::Drawable* _drawable) const
{
	render->draw(*_drawable);
}
void Core::Window::OpenMenu(const char* _name)
{
	checkLow(menus.contains(_name), std::format("[Window] => menu: '{}' doesn't exist !", _name))
	CloseAllMenus();
	menus[_name]->Open();
}
void Core::Window::CloseAllMenus()
{
	for (BaseMenu*& _menu : menus | std::ranges::views::values)
		_menu->Close();
}
void Core::Window::RegisterMenu(const char* _name, BaseMenu* _menu)
{
	checkLow((!menus.contains(_name)), "[Window] => menu: '{}' already exist !", _name)
		menus.insert(std::pair(_name, _menu));
}
void Core::Window::OnDraw()
{
	for (BaseMenu* _menu : menus | std::ranges::views::values)
	{
		if (!_menu->IsOpen())
			continue;
		_menu->Draw();
	}
	Manager::GameObjectManager::Instance()->Draw(this);
}
void Core::Window::OnUpdate()
{
	Input::Update();
	for (BaseMenu* _menu : menus | std::ranges::views::values)
	{
		if (!_menu->IsOpen())
			continue;
		_menu->OnUpdate();
	}
	Manager::GameObjectManager::Instance()->Update();
	Manager::GameObjectManager::Instance()->DestroyAllRequest();
}
void Core::Window::OnReceiveEvent(const sf::Event& _event)
{
	if (_event.type == sf::Event::Closed)
		Close();
	if (_event.type == sf::Event::Resized)
	{
		for (BaseMenu* _menu : menus | std::ranges::views::values)
			_menu->OnResize(sf::Vector2f(_event.size.width, _event.size.height));
	}
}
#pragma endregion
