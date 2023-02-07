#pragma once
#include "Engine/Utils/ObjectMacro.h"


using namespace Engine;

#include "Engine\Component\Component.h"
REGISTER_TYPE(Component)
#include "Engine\GameObject\GameObject.h"
REGISTER_TYPE(GameObject)
#include "Engine\Transform\Transform.h"
REGISTER_TYPE(Transform)

using namespace Engine::PrimaryType;

#include "Engine\PrimaryType\Boolean\Boolean.h"
REGISTER_TYPE(Boolean)
#include "Engine\PrimaryType\Integer\Integer.h"
REGISTER_TYPE(Integer)
#include "Engine\PrimaryType\Vector2\Vector2.h"
REGISTER_TYPE(Vector2)

using namespace Engine::Reflection;

#include "Engine\Reflection\Field\FieldInfo.h"
REGISTER_TYPE(FieldInfo)

using namespace Test;

#include "Test\Reflection\Json\ATest.h"
REGISTER_TYPE(ATest)

