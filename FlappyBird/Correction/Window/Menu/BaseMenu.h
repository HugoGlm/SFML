#pragma once
#include "../../Object/Object.h"
#include <vector>

class BaseMenu : public Object
{
#pragma region f/p
protected:
	std::vector<class FB_UIElement*> elements = std::vector<class FB_UIElement*>();
	bool isOpen = false;
	class Window* owner = nullptr;
#pragma endregion
#pragma region constructor
public:
	BaseMenu(Window* _owner);
	virtual ~BaseMenu() override;
#pragma endregion
#pragma region methods
private:
	void SetActive(const bool _status);
public:
	void Open();
	void Close();
	virtual void Draw();
#pragma endregion

};

