#include <RenderSystem.hpp>
#include <vector>
#include <raylib.h>
void RenderSystem::DrawEntities(
    const ComponentStorage<Vector2>& position,
    const ComponentStorage<float>& radius,
    const ComponentStorage<Color>& color,
    const ComponentStorage<Color>& overlay
) {
    for (int entity : position.entities)
        if (radius.has(entity)) {
            Vector2 pos = position.get(entity);
            DrawCircle(pos.x, pos.y, radius.get(entity), color.get(entity));
            DrawCircle(pos.x, pos.y, radius.get(entity), overlay.get(entity));
    }
}

