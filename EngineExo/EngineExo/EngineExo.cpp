#include <iostream>
#include "Engine/Utils/DebugMacro.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/GameObject/GameObject.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Engine/AssetDataBase/AssetDataBase.h"
#include "Engine/Utils/Interface/Log/ILogger.h"
#include "Test/Component/PlayerComponent.h"
#include "Test/Reflection/Json/JsonTest.h"

int main()
{
	Test::JsonTest::Test();
	
	/*Engine::GameObject* _gameObject = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "Test");
	_gameObject->AddComponent<Test::PlayerComponent>();

	Engine::AssetDataBase::CreateAsset(_gameObject, "../Asset/GameObjectTest.asset");

	Engine::Window::EngineWindow::Instance()->Open();
	Engine::Manager::GameObjectManager::Instance()->Destroy();*/
}