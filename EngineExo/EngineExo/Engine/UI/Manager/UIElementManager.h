#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <vector>

namespace Engine
{
	class UIElement;
}
namespace Engine::Manager
{
	class UIElementManager : public Engine::Utils::Singleton<UIElementManager>
	{
		DECLARE_CLASS_INFO(UIElementManager, Singleton)
#pragma region f/p
	private:
		std::vector<UIElement*> elements = std::vector<UIElement*>();
#pragma endregion
#pragma region constructor
	public:
		UIElementManager() = default;
#pragma endregion
#pragma region methods
	public:
		void Register(UIElement* _element);
		void UnRegister(UIElement* _element);
		void Update();
#pragma endregion
#pragma region override
	public:
		virtual void OnDestroy() override;
#pragma endregion

	};
}

