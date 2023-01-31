#include <iostream>
#include "Engine/Utils/DebugMacro.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/GameObject/GameObject.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Test/Component/PlayerComponent.h"
#include "Test/Reflection/Json/JsonTest.h"

int main()
{
	Test::JsonTest::Test();
	/*Engine::GameObject* object = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "circle");
	object->SetColor(sf::Color::Red);
	object->AddComponent<Test::PlayerComponent>();
	Engine::Window::EngineWindow::Instance()->Open();
	Engine::Manager::GameObjectManager::Instance()->Destroy();*/
}