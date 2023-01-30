#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils/Singleton/Singleton.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../Utils/DebugMacro.h"

namespace Engine::Window
{
	template<typename T>
	class Window : public Engine::Utils::Singleton<T>
	{
		DECLARE_CLASS_INFO()
#pragma region f/p
		protected:
			sf::RenderWindow* renderer = nullptr;
			const char* name = "default window";
			PrimaryType::Integer width = 0;
			PrimaryType::Integer height = 0;
			PrimaryType::Boolean hasFocus = false;
			sf::Event currentEvent = sf::Event();
#pragma endregion
#pragma region constructor
	public:
		Window() = delete;
		Window(const char* _name, const int _width = 800, const int _height = 600)
		{
			name = _name;
			width = _width;
			height = _height;
		}
		Window(const Window&) = delete;
#pragma endregion
#pragma region methods
	private:
		void Update()
		{
			while (renderer->isOpen())
			{
				while (renderer->pollEvent(currentEvent))
				{
					if (currentEvent.type == sf::Event::Closed)
						Close();
					if (currentEvent.type == sf::Event::LostFocus || currentEvent.type == sf::Event::GainedFocus)
						SetFocus(currentEvent.type);
					if (hasFocus)
						OnReceiveEvent(currentEvent);
				}
			}
		}
		void Setfocus(const sf::Event::EventType& _eventType)
		{
			hasFocus = _eventType == sf::Event::LostFocus ? false : true;
			LOG_FORMAT("[Engine] Focus : ", hasFocus.ToString().ToCstr());
		}
	public:
		virtual void Open()
		{
			renderer = new sf::RenderWindow(sf::VideoMode(width, height), name.ToCstr());
			Update();
		}
		void Close()
		{
			renderer->close();
		}
		PrimaryType::Boolean IsOpen() const
		{
			return renderer->isOpen();
		}
		PrimaryType::Boolean HasFocus() const
		{
			return hasFocus;
		}
		void SetFramesLimit(int _frame) const
		{
			renderer->setFramerateLimit(_frame);
		}
		void Draw(sf::Drawable* _drawable) const
		{
			renderer->draw(*_drawable);
		}
	protected:
		virtual void OnUpdate() {}
		virtual void OnDraw() {}
		virtual void OnClear() const {}
		virtual void OnReceiveEvent(const sf::Event& _event) {}
		void Clear() const
		{
			renderer->clear();
			OnClear();
		}
		void display()
		{
			renderer->display();
		}
#pragma endregion
#pragma region override
	public:
		PrimaryType::String ToString() const override;
#pragma endregion

	};
}