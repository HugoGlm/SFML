#pragma once
#include "../../Object/Object.h"

namespace Core
{
	namespace Utils
	{
		class Path : public Object
		{
			DECLARE_CLASS_INFO(Path, Object)
		public:
			static inline char DirectorySeparator = '/';
			static std::string GetPath(const std::string& _path);
			static std::string Combine(const std::initializer_list<std::string>& _paths);
		};
	}
}