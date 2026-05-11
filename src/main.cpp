#include <iostream>
#include <ComponentStorage.hpp>
#include <RenderSystem.hpp>
#include <MovementSystem.hpp>
#include <BounceSystem.hpp>
void SpawnBall(
    ComponentStorage<Vector2>& positionStorage,
    ComponentStorage<Vector2>& velocityStorage,
    ComponentStorage<float>& radiusStorage
)
int main() {
    InitWindow(800, 600, "ECS Test");
    SetTargetFPS(60);
    ComponentStorage<Vector2> PositionStorage;
    PositionStorage.add(0, {50,50});
    PositionStorage.add(1, {200,500});
    PositionStorage.add(2, {100, 100});
    ComponentStorage<Vector2> VelocityStorage;
    VelocityStorage.add(0, {1,1});
    VelocityStorage.add(1, {0.5,0.5});
    VelocityStorage.add(2, {2,0.5});
    ComponentStorage<float> RadiusStorage;
    RadiusStorage.add(0, 40.0f);
    RadiusStorage.add(1, 60.0f);
    RadiusStorage.add(2, 20.0f);
    while (!WindowShouldClose()) {
        MovementSystem::ApplyVelocity(VelocityStorage, PositionStorage);
        BounceSystem::ApplyBounce(VelocityStorage, PositionStorage, RadiusStorage);
        BeginDrawing();
        ClearBackground(WHITE);
        RenderSystem::DrawEntities(PositionStorage, RadiusStorage);
        EndDrawing();
    }
    
    return 0;
}