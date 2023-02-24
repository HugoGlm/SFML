#pragma once
#include <SFML/Graphics.hpp>

class EngineWindow
{
#pragma region f/p
private:
	float width = 1920;
	float height = 1080;
	const char* title = "Default Window";
	sf::RenderWindow* window = nullptr;
protected:
	bool eventIfNotFocus = false;
#pragma endregion
#pragma region constructor
public:
	EngineWindow() = default;
	EngineWindow(const float _width, const float _height, const char* _title);
	EngineWindow(const EngineWindow& _copy) = delete;
	virtual ~EngineWindow();
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


