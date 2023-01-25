#pragma once
#include "../../../Window/Menu/BaseMenu.h"
#include "../../../Utils/GIF/Gif.h"

class FB_Button;
class FB_Image;

class FB_MainMenu : public BaseMenu
{
#pragma region f/p
private:
	FB_Image* logoTitle = nullptr;
	FB_Button* playButton = nullptr;
	FB_Button* scoreBoardButton = nullptr;
	sf::Sprite* gifSprite = nullptr;
	Gif gif = Gif("C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/nyan-cat-gif.gif");
#pragma endregion
#pragma region constructor
public:
	FB_MainMenu(Window* _owner);
	virtual ~FB_MainMenu() override;
#pragma endregion
#pragma region methods
private:
	void InitLogoTitle();
	void InitPlayButton();
public:
	FB_Button* PlayButton() const;
	FB_Button* ScoreBoardButton() const;
#pragma endregion
#pragma region override
public:
	void Draw();
#pragma endregion

};

