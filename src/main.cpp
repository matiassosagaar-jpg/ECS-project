#include <iostream>
#include <PositionStorage.hpp>
#include <RenderSystem.hpp>
int main() {
    InitWindow(800, 600, "ECS Test");
    SetTargetFPS(60);
    PositionStorage positions;
    positions.add(0, {20,50});
    positions.add(1, {200,500});
    positions.add(2, {100, 100});

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        RenderSystem::DrawEntities(positions);
        EndDrawing();
    }
    
    return 0;
}