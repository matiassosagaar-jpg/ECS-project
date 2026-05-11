#include <BounceSystem.hpp>

void BounceSystem::ApplyBounce(
    ComponentStorage<Vector2>& velocity, 
    const ComponentStorage<Vector2>& position,
    const ComponentStorage<float>& radius
) {
        Vector2 ScreenSize {
        static_cast<float>(GetScreenWidth()), 
        static_cast<float>(GetScreenHeight())
    };
    for (const int entity : velocity.entities) {
        if (position.has(entity) && radius.has(entity)) {
            if (position.get(entity).x + radius.get(entity) >= ScreenSize.x ||
            position.get(entity).x - radius.get(entity) <= 0) { // Note the hardcoded radius - > Will add Radius component later
                velocity.get(entity).x *= -1;
            }
            if (position.get(entity).y + radius.get(entity) >= ScreenSize.y ||
            position.get(entity).y - radius.get(entity) <= 0) {
                velocity.get(entity).y *= -1;
            }
        }
    }
}