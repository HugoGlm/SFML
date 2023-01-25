#pragma once
#include "../../../Window/Menu/BaseMenu.h"

class FB_GameOverMenu : public BaseMenu
{
#pragma region f/p
private:
	class FB_Image* gameOverImage = nullptr;
	FB_Image* titleImage = nullptr;
	class FB_Button* restartButton = nullptr;
	class FB_Label* scoreText = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_GameOverMenu(Window* _owner);
	virtual ~FB_GameOverMenu() override;
#pragma endregion
#pragma region methods
private:
	void InitRestartButton(const float& _centerWidth, const float& _centerHeight);
	void InitTitleImage(Window* _owner, const float& _centerWidth);
	void InitGameOverImage(Window* _owner, const float& _centerWidth, const float& _centerHeight);
	void InitScoreText(const float& _centerWidth, const float& _centerHeight);
public:
	FB_Button* RestartButton();
	void SetScore(const int _score);
#pragma endregion
#pragma region override
public:
	virtual void Draw() override;
#pragma endregion

};

