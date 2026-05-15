#include <iostream>
#include <ComponentStorage.hpp>
#include <RenderSystem.hpp>
#include <MovementSystem.hpp>
#include <BounceSystem.hpp>
#include <EntitySpawner.hpp>
#include <stdexcept>
#include "CollisionSystem.hpp"
int main() {
    std::random_device rd; //getting random seed from hardware
    std::mt19937 gen(rd()); //each time I call gen() it gives me the next generated number and the machine updates it's state
    InitWindow(800, 600, "ECS Test");
    SetTargetFPS(60);
    ComponentStorage<Vector2> PositionStorage;
    
    ComponentStorage<Vector2> VelocityStorage;
    
    ComponentStorage<float> RadiusStorage;

    ComponentStorage<Color> ColorStorage;

    ComponentStorage<Color> OverlayStorage;
    //spawning 20 random balls
    for (size_t i {0}; i < 20; i++) {
        EntitySpawner::SpawnBall(
            PositionStorage, VelocityStorage, RadiusStorage, ColorStorage, OverlayStorage, gen, //storages and generator
            {static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())}, // position
            {5.0f,5.0f}, 50.0f, GREEN); // velocity, radius & color
    }
    
    while (!WindowShouldClose()) {
        // setting al their overlays to BLANK
        for (Color& overlay : OverlayStorage.component)
            overlay = BLANK;
        // Hilighting positions
        CollisionSystem::HighlightCollisions_Ball(
            PositionStorage, RadiusStorage, OverlayStorage, RED
        );
        CollisionSystem::SwapVelocityInCollision_Ball(
            PositionStorage, RadiusStorage, VelocityStorage
        );
        // so, the balls that are in current collision this frame will be red, ant the ones that aren't will be green
        MovementSystem::ApplyVelocity(VelocityStorage, PositionStorage);
        BounceSystem::ApplyBounce(VelocityStorage, PositionStorage, RadiusStorage);
        BeginDrawing();
        ClearBackground(BLACK);
        RenderSystem::DrawEntities(PositionStorage, RadiusStorage, ColorStorage, OverlayStorage);
        EndDrawing();
    }
    
    return 0;
}