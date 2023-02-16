#pragma once
#include "../Element/UIElement.h"
#include "../../Event/Action/Action.h"
#include "../Interface/IPointerMoveHandler.h"
#include "../../PrimaryType/Float/Float.h"

namespace Engine::UI
{
	class Slider : public UIElement, public IPointerMoveHandler
	{
		DECLARE_CLASS_INFO(Slider, UIElement)
#pragma region f/p
	private:
		sf::CircleShape* handle = nullptr;
		sf::RectangleShape* box = nullptr;
		float minValue = 0.0f;
		float maxValue = 100.0f;
		float currentValue = 0.0f;
		Action<float> onValueChanged = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Slider();
		Slider(float _min, float _max, float _value);
		Slider(float _value);
		~Slider() override;
#pragma endregion
#pragma region methods
	private:
		void UpdateHandlePosition();
	public:
		void SetValue(float _value);
		void SetMin(float _min);
		void SetMax(float _max);
		Engine::PrimaryType::Float Value();
#pragma endregion
#pragma region override
	public:
		void Draw(sf::RenderWindow* _window) override;
		void SetPosition(const PrimaryType::Vector2& _position) override;
		void OnPointerMove(float _x, float _y) override;
#pragma endregion

	};
}
