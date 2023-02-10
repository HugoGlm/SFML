#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <vector>

namespace Engine
{
	namespace Window
	{
		class EngineWindow;
	}
	namespace UI
	{
		class UIElement;
		namespace Manager
		{
			class UIElementManager : public Engine::Utils::Singleton<UIElementManager>
			{
				DECLARE_CLASS_INFO(UIElementManager, Singleton)
#pragma region f/p
			private:
				static inline std::vector<UIElement*> elements = std::vector<UIElement*>();
#pragma endregion
#pragma region constructor
			public:
				UIElementManager() = default;
#pragma endregion
#pragma region methods
			public:
				static void Register(UIElement* _element);
				static void UnRegister(UIElement* _element);
				void Update() const;
				void Draw(Window::EngineWindow* _window) const;
				void OnDestroy() override;
#pragma endregion

			};
		}
	}
}

