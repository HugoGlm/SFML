#pragma once
#include <SFML/Graphics.hpp>

#define WIDTH 900
#define HEIGHT 800

class Window
{
#pragma region f/p
private:
	float width = 900;
	float height = 800;
	const char* title = "Flappy Bird";
protected:
	sf::RenderWindow* window = nullptr;
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
	bool IsOpen();
	bool HasFocus();
	void SetFrameLimit(const int _frame);
	void Draw(sf::Drawable* _drawable);
protected:
	virtual void OnDraw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnReceiveEvent(const sf::Event& _event);
#pragma endregion

};

