#include <iostream>
#include "Engine/Utils/DebugMacro.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/GameObject/GameObject.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Engine/Manager/FontManager.h"
#include "Engine/Manager/Texture/TextureManager.h"
#include "Engine/AssetDataBase/AssetDataBase.h"
#include "Engine/Utils/Interface/Log/ILogger.h"
#include "Test/Component/PlayerComponent.h"
#include "Test/Reflection/Json/JsonTest.h"

using namespace Engine;

int main()
{
	Manager::FontManager::Instance()->Init();
	Manager::TextureManager::Instance()->Init();
	Engine::Window::EngineWindow::Instance()->Open();

	Manager::GameObjectManager::Instance()->Destroy();
	Manager::FontManager::Instance()->Destroy();
	Manager::TextureManager::Instance()->Destroy();
}