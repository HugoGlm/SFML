#pragma once
#include "../../Singleton/Singleton.h"
#include <vector>

class FB_UIElement;

class UIElementManager : public Singleton<UIElementManager>
{
#pragma region f/p
private:
	std::vector<FB_UIElement*> elements = std::vector<FB_UIElement*>();
#pragma endregion
#pragma region constructor
public:
	UIElementManager() = default;
#pragma endregion
#pragma region methods
public:
	void Register(FB_UIElement* _element);
	void UnRegister(FB_UIElement* _element);
	void Update();
#pragma endregion
#pragma region override
public:
	virtual void OnDestroy() override;
#pragma endregion

};

