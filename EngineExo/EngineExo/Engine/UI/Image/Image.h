#pragma once
#include "../UIElement.h"

namespace Engine::Window
{
	class EngineWindow;
}
namespace Engine::Image
{
	class Image : public UIElement
	{
		DECLARE_CLASS_INFO(Image, UIElement)
#pragma region f/p
	private:
		sf::Sprite* sprite = nullptr;
		sf::Texture* texture = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Image(Window::EngineWindow* _owner, const char* _path);
		~Image() override;
#pragma endregion
#pragma region methods
	private:
		void Free();
	public:
		sf::FloatRect GlobalBounds() const;
#pragma endregion
#pragma region override
	public:
		virtual void SetPosition(const sf::Vector2f& _position) override;
		virtual void SetScale(const sf::Vector2f& _scale) override;
		virtual void SetOrigin(const sf::Vector2f& _origin) override;
		virtual void Draw(Window::EngineWindow* _window) override;
		virtual sf::FloatRect GetGlobalBounds() override;
#pragma endregion

	};
}
