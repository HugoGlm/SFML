#include "TextureManager.h"
#include <filesystem>
#include <ranges>
#include "../../Utils/DebugMacro.h"

namespace fs = std::filesystem;

#pragma region methods
void Engine::Manager::TextureManager::Init()
{
	LoadTexture("C:/Users/GUIL2804/source/repos/SFML/EngineExo/Texture");
}
void Engine::Manager::TextureManager::LoadTexture(const char* _path)
{
	for (const fs::directory_entry& _entry : fs::recursive_directory_iterator(_path))
	{
		if (!_entry.is_regular_file())
			continue;
		const fs::path _filePath = _entry.path();
		if (_filePath.extension() != ".ttf" && _filePath.extension() != ".otf")
			continue;
		sf::Texture* _texture = new sf::Texture();
		if (!_texture->loadFromFile(_filePath.string()))
		{
			LOG_ERROR(_filePath.string() + " can't load font !")
				continue;
		}
		PrimaryType::String _name = _filePath.string().c_str();
		_name = _name.Replace('\\', '/');
		_name = _name.SubString(_name.FindLastOf('/') + 1, _name.FindFirstOf('.')).Trim();
		textures.insert(std::pair<std::string, sf::Texture*>(_name.ToCstr(), _texture));
	}
}
sf::Texture* Engine::Manager::TextureManager::GetTexture(const std::string& _textureName)
{
	check((textures.contains(_textureName)), _textureName + " doesn't exist !", nullptr)
		return textures[_textureName];
}
#pragma endregion

#pragma region override
void Engine::Manager::TextureManager::OnDestroy()
{
	for (sf::Texture*& _texture : textures | std::ranges::views::values)
	{
		delete _texture;
		_texture = nullptr;
	}
	textures.clear();
}
#pragma endregion

