#pragma once
#include "../../Core/Window/Window.h"

namespace Game
{
	class GameWindow : public Core::Window
	{
		DECLARE_CLASS_INFO(GameWindow, Window)
#pragma region constructor
	public:
		GameWindow();
#pragma endregion
#pragma region methods
	public:
		void StartGame();
#pragma endregion

	};
}


