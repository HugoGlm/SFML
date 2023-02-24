#pragma once
#include "Engine/EngineWindow.h"

class Window : public EngineWindow
{
#pragma region f/p
private:
	int isConnected = 0;
	sf::Sprite* background = nullptr;
	sf::Texture* textureBackground = nullptr;
	sf::Sprite* perso = nullptr;
	sf::Texture* texturePerso = nullptr;
	sf::Texture* textureCrouch = nullptr;
#pragma endregion
#pragma region constructor
public:
	Window();
	~Window() override;
#pragma endregion
#pragma region override
protected:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion
};

