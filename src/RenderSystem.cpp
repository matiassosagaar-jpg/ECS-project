#include <RenderSystem.hpp>
#include <vector>
#include <raylib.h>

void RenderSystem::DrawEntities(
    const ComponentStorage<Vector2>& position,
    const ComponentStorage<float>& radius
) {
    for (int entity : position.entities)
        if (radius.has(entity)) {
            Vector2 pos = position.get(entity);
            DrawCircle(pos.x, pos.y, radius.get(entity), RED);
    }
}
