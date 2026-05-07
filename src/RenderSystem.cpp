#include <RenderSystem.hpp>
#include <vector>
#include <raylib.h>
namespace RenderSystem {
    void DrawEntities(const PositionStorage& data) {
        for (const Vector2& pos : data.position)
            DrawCircle(pos.x, pos.y, 40.0f, RED);
    }
}