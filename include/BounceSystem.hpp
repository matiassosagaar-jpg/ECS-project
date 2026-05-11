#pragma once
#include <ComponentStorage.hpp>
namespace BounceSystem {
    void ApplyBounce(ComponentStorage<Vector2>& velocity, 
        const ComponentStorage<Vector2>& poisition,
        const ComponentStorage<float>& radius
    );
}