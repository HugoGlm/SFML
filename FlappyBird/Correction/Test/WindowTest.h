#pragma once
#include "../Window/Window.h"

class WindowTest : public Window
{
#pragma region f/p
private:
	sf::RectangleShape* shape = nullptr;
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;
#pragma endregion
#pragma region constructor
public:
	WindowTest();
	~WindowTest() override;
#pragma endregion
#pragma region override
protected:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion

};

