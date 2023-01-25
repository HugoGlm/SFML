#include "FB_MainMenu.h"
#include "../../../UI/Button/FB_Button.h"
#include "../../../UI/image/FB_Image.h"
#include "../../../Window/Window.h"

#pragma region constructor
FB_MainMenu::FB_MainMenu(Window* _owner) : BaseMenu(_owner)
{
	InitLogoTitle();
	InitPlayButton();
	/*gifSprite = new sf::Sprite();
	gifSprite->setScale(sf::Vector2f(0.2f, 0.2f));*/
}
FB_MainMenu::~FB_MainMenu()
{
	
}
#pragma endregion

#pragma region methods

void FB_MainMenu::InitLogoTitle()
{
	logoTitle = new FB_Image(owner, "C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/Flappy_Logo.png");
	logoTitle->SetPosition(sf::Vector2f((owner->Width() / 2) - 150, 20));
	logoTitle->SetScale(sf::Vector2f(0.1f, 0.1f));
	logoTitle->SetOrigin(sf::Vector2f(logoTitle->GlobalBounds().width / 2, logoTitle->GlobalBounds().height / 2));
	elements.push_back(logoTitle);
}
void FB_MainMenu::InitPlayButton()
{
	playButton = new FB_Button(owner, "C:/Users/GUIL2804/source/repos/P1-O3D-cpp/SFML/FlappyBird/FlappyBirdBg/flappybird_play_button.png");
	playButton->SetScale(sf::Vector2f(0.3f, 0.3f));
	const sf::Vector2f _position = sf::Vector2f((owner->Width() / 2) - (playButton->GetGlobalBounds().width + 100), owner->Height() / 2);
	playButton->SetPosition(_position);
	elements.push_back(playButton);
}
FB_Button* FB_MainMenu::PlayButton() const
{
	return playButton;
}
FB_Button* FB_MainMenu::ScoreBoardButton() const
{
	return scoreBoardButton;
}
#pragma endregion

#pragma region override
void FB_MainMenu::Draw()
{
	BaseMenu::Draw();
	/*gif.Update(*gifSprite);
	owner->Draw(gifSprite);*/
}
#pragma endregion