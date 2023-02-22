#include "AssetDataBase.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../IO/File.h"
#include <filesystem>
#include <fstream>

#pragma region methods
void Engine::AssetDataBase::CreateAsset(Object* _asset, PrimaryType::String _path)
{
	if (_path.StartWith("Assets"))
	{
		const std::string _assetPath = std::filesystem::current_path().string();
		_path = PrimaryType::String((_assetPath + "/" + _path.ToCstr()).c_str());
	}
	std::ofstream _stream = std::ofstream(_path);
	_asset->Serialize(_stream);
	_stream.close();
}
std::vector<Engine::Object*> Engine::AssetDataBase::LoadAllAssets()
{
	std::vector<Object*> _result = std::vector<Object*>();
	const std::string _path = std::format("{}/Asset/", std::filesystem::current_path().string());
	for (const std::filesystem::directory_entry& _entry : std::filesystem::recursive_directory_iterator(_path))
	{
		File _file = File(_entry.path().string());
		PrimaryType::String _className = _file.ReadAllLines()[0].Replace("\"", "");
		_className = _className.SubString(0, _className.FindFirstOf(' ')).Trim();
		Object* _data = TypeOfData::Types[_className.ToCstr()]->Clone();
		std::ifstream _stream(_entry.path());
		_data->DeSerialize(_stream);
		_result.emplace_back(_data);
	}
	return _result;
}
#pragma endregion

