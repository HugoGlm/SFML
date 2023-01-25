#pragma once
#include "../FB_UIElement.h"

class FB_Image : public FB_UIElement
{
#pragma region f/p
private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
#pragma endregion
#pragma region constructor
	public:
		FB_Image(Window* _owner, const char* _path);
		FB_Image(const FB_Image& _copy);
		virtual ~FB_Image() override;
#pragma endregion
#pragma region methods
private:
	void Free();
public:
	sf::FloatRect GlobalBounds() const;
#pragma endregion
#pragma region override
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
#pragma endregion



	// Inherited via FB_UIElement
	virtual sf::FloatRect GetGlobalBounds() override;

};

