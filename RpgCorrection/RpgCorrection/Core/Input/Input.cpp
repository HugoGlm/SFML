#include "Input.h"

void Core::Input::Init()
{
	for (EKey key : EKeySupport::Values())
	{
		keys.insert(std::pair(key, EKeyType::None));
	}
}
void Core::Input::Update()
{
	for (EKey key : EKeySupport::Values())
	{
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key))
		{
			if (keys[key] == EKeyType::None)
				keys[key] = EKeyType::Down;
			else if (keys[key] == EKeyType::Down)
				keys[key] = EKeyType::Pressed;
		}
		else
		{
			if (keys[key] == EKeyType::Up)
				keys[key] = EKeyType::None;
			else if (keys[key] == EKeyType::Down || keys[key] == EKeyType::Pressed)
				keys[key] = EKeyType::Up;
		}
	}
}
bool Core::Input::IsKeyDown(const EKey& _key)
{
	return keys[_key] == EKeyType::Down;
}
bool Core::Input::IsKey(const EKey& _key)
{
	return keys[_key] == EKeyType::Pressed;

}
bool Core::Input::IsKeyUp(const EKey& _key)
{
	return keys[_key] == EKeyType::Up;

}
