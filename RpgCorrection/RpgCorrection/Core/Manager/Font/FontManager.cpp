#include "FontManager.h"
#include "../../Environment/Environment.h"
#include "../../Utils/Debug/Debug.h"
#include <vector>

void Core::Manager::FontManager::Init()
{
	std::vector<std::string> _files = Environment::GetAllFilesWithExtension(Environment::AssetPath.c_str(), ".ttf");
	for (std::string _path : _files)
	{
		sf::Font* _font = new sf::Font();
		if (!_font->loadFromFile(_path))
		{
			LOG_ERROR(std::format("[FontManager] =< error n load {} font !", _path));
			delete _font;
			continue;
		}
		std::string _fileName = _path.substr(_path.find_last_of('/') + 1);
		_fileName = _fileName.substr(0, _fileName.find_first_of('.'));
		items.insert(std::pair(_fileName, _font));
	}
}
