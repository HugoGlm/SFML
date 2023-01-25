#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>

class FB_Score : public Object
{
#pragma region f/p
private:
	int score = 0;
	class FB_Label* scoreText = nullptr;
	class Window* owner = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_Score(Window* _owner);
	virtual ~FB_Score() override;
#pragma endregion
#pragma region methods
public:
	int CurrentScore() const;
	void UpdateScore();
	void Draw();
	void SetPosition(const sf::Vector2f& _position);
	void Reset();
#pragma endregion

};

