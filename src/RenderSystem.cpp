#include <RenderSystem.hpp>
#include <vector>
#include <raylib.h>
namespace RenderSystem {
    void DrawEntities(const ComponentStorage<Vector2>& position) {
        for (const Vector2& pos : position.component)
            DrawCircle(pos.x, pos.y, 40.0f, RED);
    }
}