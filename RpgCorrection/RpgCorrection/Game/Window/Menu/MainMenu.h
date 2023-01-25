#pragma once
#include "../../../Core/Window/Menu/BaseMenu.h"
#include "../../../Core/UI/Image/Image.h"
#include "../../../Core/UI/Button/Button.h"

namespace Game
{
#define BACKGROUND_MAIN_MENU_PATH "background_main_menu"
#define TITLE_MAIN_MENU_PATH "title_main"
#define PLAY_BUTTON_MAIN_MENU_PATH "play_button"
#define QUIT_BUTTON_MAIN_MENU_PATH "quit_button"

	class MainMenu : public Core::BaseMenu
	{
		DECLARE_CLASS_INFO(MainMenu, BaseMenu)
#pragma region f/p
	private:
		Core::UI::Image* background = nullptr;
		Core::UI::Image* title = nullptr;
		Core::UI::Button* playButton = nullptr;
		Core::UI::Button* quitButton = nullptr;
#pragma endregion
#pragma region constructor
	public:
		void InitBackground();
		void InitTitle();
		void InitPlayButton();
		void InitQuitButton();
		MainMenu(Core::Window* _owner);
		MainMenu(const MainMenu& _copy);
#pragma endregion
#pragma region method
	public:
		Core::UI::Button* PlayButton();
		Core::UI::Button* QuitButton();
#pragma endregion
#pragma region override
	public:
		void OnResize(const sf::Vector2f& _size) override;
#pragma endregion

	};
}

