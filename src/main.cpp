#include <iostream>
#include <ComponentStorage.hpp>
#include <RenderSystem.hpp>
#include <MovementSystem.hpp>
#include <BounceSystem.hpp>
#include <EntitySpawner.hpp>
int main() {
    std::random_device rd; //getting random seed from hardware
    std::mt19937 gen(rd()); //each time I call gen() it gives me the next generated number and the machine updates it's state
    InitWindow(800, 600, "ECS Test");
    SetTargetFPS(60);
    ComponentStorage<Vector2> PositionStorage;
    
    ComponentStorage<Vector2> VelocityStorage;
    
    ComponentStorage<float> RadiusStorage;

    ComponentStorage<Color> ColorStorage;
    
    for (size_t i {0}; i < 20; i++) {
        EntitySpawner::SpawnBall(
            PositionStorage, VelocityStorage, RadiusStorage, ColorStorage, gen, //storages and generator
            {static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())}, // position
            {5.0f,5.0f}, 50.0f, GREEN); // velocity, radius & color
    }
    while (!WindowShouldClose()) {
        MovementSystem::ApplyVelocity(VelocityStorage, PositionStorage);
        BounceSystem::ApplyBounce(VelocityStorage, PositionStorage, RadiusStorage);
        BeginDrawing();
        ClearBackground(BLACK);
        RenderSystem::DrawEntities(PositionStorage, RadiusStorage, ColorStorage);
        EndDrawing();
    }
    
    return 0;
}