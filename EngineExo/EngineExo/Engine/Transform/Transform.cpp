#include "Transform.h"
#include "../Utils/DebugMacro.h"

Engine::Transform::Transform(const Transform& _copy)
{
    position = _copy.position;
}
Engine::Object& Engine::Transform::operator=(const Object* _obj)
{
    const Transform* _other = dynamic_cast<const Transform*>(_obj);
    check((_other != nullptr), "[Transform] operator= _other is not Transform", *this)
        super::operator=(_other);
    position = _other->position;
    return *this;
}
