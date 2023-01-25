#include "FB_TextureManager.h"
#include <format>

#pragma region methods
sf::Texture* FB_TextureManager::Get(const char* _path)
{
	if (!textures.contains(_path))
	{
		sf::Texture* _texture = new sf::Texture();
		if (!_texture->loadFromFile(_path))
			throw std::exception(std::format("[Texture Manager] => can't load texture at path: {}", _path).c_str());
		textures.insert(std::pair(_path, _texture));
		return _texture;
	}
	return textures[_path];
}
#pragma endregion

#pragma region override
void FB_TextureManager::OnDestroy()
{
	for (std::pair<const char*, sf::Texture*> _pair : textures)
		delete _pair.second;
	textures.clear();
}
#pragma endregion

