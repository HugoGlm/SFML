#include "Path.h"
#pragma warning(disable: 4996)


std::string Core::Utils::Path::GetPath(const std::string& _path)
{
	std::string _result = _path;
	size_t _startPos = 0;
	const std::string _from = "\\";
	const std::string _to = "/";
	while ((_startPos = _result.find(_from, _startPos))!= std::string::npos)
	{
		_result.replace(_startPos, _from.size(), _to);
		_startPos += _to.size();
	}
	return _result;
}

std::string Core::Utils::Path::Combine(const std::initializer_list<std::string>& _paths)
{
	std::string _result = "";
	int _index = 0;
	const size_t _size = _paths.size();
	for (const std::string& _path : _paths)
	{
		_result += _path;
		if (_index < _size - 1)
			_result += DirectorySeparator;
		_index++;
	}
	return GetPath(_result);
}