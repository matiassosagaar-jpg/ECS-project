#pragma once
#include "ComponentStorage.hpp"
/* 
Since the Movement System Only Needs a position to draw,
it makes sense it expects a Vector2 and not any other
kind of type
*/
namespace MovementSystem {
    void ApplyVelocity(const ComponentStorage<Vector2>& velocity,
                        ComponentStorage<Vector2>& position);
}