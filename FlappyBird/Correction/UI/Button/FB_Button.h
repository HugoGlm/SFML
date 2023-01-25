#pragma once
#include "../FB_UIElement.h"
#include "../../Event/Delegate/Delegate.h"

class FB_Image;

class FB_Button : public FB_UIElement
{
#pragma region f/p
private:
	FB_Image* image = nullptr;
public:
	Delegate<void> OnClick = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_Button(Window* _owner, const char* _path);
	FB_Button(const FB_Button& _copy);
	virtual ~FB_Button() override;
#pragma endregion
#pragma region methods
public:

#pragma endregion
#pragma region override
public:
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
	virtual void  OnUpdate();
#pragma endregion


	// Inherited via FB_UIElement
	virtual sf::FloatRect GetGlobalBounds() override;

};

