#pragma once
#include "../Base/BaseManager.h"
#include <SFML/Graphics.hpp>

namespace Core
{
	namespace Manager
	{
		class TextureManager : public BaseManager<TextureManager, sf::Texture>
		{
			DECLARE_CLASS_INFO(TextureManager, BaseManager)
		public:
			void Init() override;
		};
	}
}

