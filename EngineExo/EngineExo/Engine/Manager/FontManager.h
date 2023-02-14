#pragma once
#include "../Utils/Singleton/Singleton.h"
#include <SFML/Graphics.hpp>

namespace Engine::Manager
{
	class FontManager : public Utils::Singleton<FontManager>
	{
#pragma region f/p
	private:
		std::map<std::string, sf::Font*> fonts = std::map<std::string, sf::Font*>();
#pragma endregion
#pragma region constructor
	public:
		FontManager() = default;
#pragma endregion
#pragma region methods
	public:
		void Init();
		void LoadFont(const char* _path);
		sf::Font* GetFont(const std::string& _fontName);
#pragma endregion
#pragma region override
	public:
		void OnDestroy() override;
#pragma endregion

	};
}
