#include <iostream>
#include <ComponentStorage.hpp>
#include <RenderSystem.hpp>
#include <MovementSystem.hpp>
int main() {
    InitWindow(800, 600, "ECS Test");
    SetTargetFPS(60);
    ComponentStorage<Vector2> PositionStorage;
    PositionStorage.add(0, {20,50});
    PositionStorage.add(1, {200,500});
    PositionStorage.add(2, {100, 100});
    ComponentStorage<Vector2> VelocityStorage;
    VelocityStorage.add(2, {1,1});
    while (!WindowShouldClose()) {
        MovementSystem::ApplyVelocity(VelocityStorage, PositionStorage);
        BeginDrawing();
        ClearBackground(WHITE);
        RenderSystem::DrawEntities(PositionStorage);
        EndDrawing();
    }
    
    return 0;
}