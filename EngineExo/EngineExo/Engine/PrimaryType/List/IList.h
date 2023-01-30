#pragma once

namespace Engine::PrimaryType
{
	class Integer;

	class IList
	{
	public:
		virtual ~IList() = default;
		virtual Integer Count() const = 0;
	};
}