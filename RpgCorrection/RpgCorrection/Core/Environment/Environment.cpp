#include "Environment.h"
#include "../Utils/Path/Path.h"
#include <filesystem>

const std::string Core::Environment::CurrentDirectory = std::filesystem::current_path().string();
const std::string Core::Environment::AssetPath = Utils::Path::Combine({ CurrentDirectory, "Asset" });

std::vector<std::string> Core::Environment::GetAllFilesWithExtension(const char* _directory, const char* _extension)
{
	std::vector<std::string> _result = std::vector<std::string>();

	if (!std::filesystem::is_directory(_directory))
		throw std::exception(std::format("[Environment] => {} is not directory !", _directory).c_str());

	for (const std::filesystem::directory_entry& _entry : std::filesystem::recursive_directory_iterator(_directory))
	{
		if (std::filesystem::is_regular_file(_entry) && _entry.path().extension() == _extension)
		{
			_result.push_back(Utils::Path::GetPath(_entry.path().string()));
		}
	}
	return _result;
}