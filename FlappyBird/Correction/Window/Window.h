#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>
#include <map>

class BaseMenu;

class Window : public Object
{
#pragma region f/p
protected:
	float width = 900;
	float height = 800;
	const char* title = "default Window";
	sf::RenderWindow* window = nullptr;
	std::map<const char*, BaseMenu*> menus = std::map<const char*, BaseMenu*>();
protected:
	bool eventIfNotFocus = false;
#pragma endregion
#pragma region constructor
public:
	Window() = default;
	Window(const float _width, const float _height, const char* _title);
	Window(const Window& _copy) = delete;
	virtual ~Window();
#pragma endregion
#pragma region methods
private:
	void Update();
public:
	void Open();
	void Close();
	int Width();
	int Height();
	bool IsOpen() const;
	bool HasFocus() const;
	void SetFrameLimit(const int _frame);
	void Draw(sf::Drawable* _drawable);
	sf::RenderWindow* Renderer() const;
protected:
	void CloseAllMenus();
	void OpenMenu(const char* _name);
	void RegisterMenu(const char* _name, BaseMenu* _menu);
	virtual void InitMenus();
	virtual void OnDraw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnReceiveEvent(const sf::Event& _event);
#pragma endregion

};

