#pragma once
#include "../Window.h"

class WindowGame : public Window
{
#pragma region f/p
private:
	sf::RectangleShape* shapeBackground = nullptr;
	sf::RectangleShape* pipeUp = nullptr;
	sf::RectangleShape* pipeUpTwo = nullptr;
	sf::RectangleShape* pipeUpTree = nullptr;
	sf::RectangleShape* pipeDown = nullptr;
	sf::RectangleShape* pipeDownTwo = nullptr;
	sf::RectangleShape* pipeDownTree = nullptr;
	sf::RectangleShape* shapeBird = nullptr;
	sf::Texture* textureBackground = nullptr;
	sf::Texture* pipeDownTexture = nullptr;
	sf::Texture* pipeDownTwoTexture = nullptr;
	sf::Texture* pipeDownTreeTexture = nullptr;
	sf::Texture* pipeUpTexture = nullptr;
	sf::Texture* pipeUpTwoTexture = nullptr;
	sf::Texture* pipeUpTreeTexture = nullptr;
	sf::Texture* bird = nullptr;
	sf::Text* showScore = nullptr;
	sf::Font* fontScore = nullptr;

	class WindowScore* windowScore = nullptr;
#pragma endregion
#pragma region constructor
public:
	WindowGame();
	~WindowGame() override;
#pragma endregion
#pragma region override
public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion

};

