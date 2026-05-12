#include <iostream>
#include <ComponentStorage.hpp>
#include <RenderSystem.hpp>
#include <MovementSystem.hpp>
#include <BounceSystem.hpp>
#include <random>
void SpawnBall(
    ComponentStorage<Vector2>& positionStorage,
    ComponentStorage<Vector2>& velocityStorage,
    ComponentStorage<float>& radiusStorage,
    std::mt19937& generator, // passing the generator by reference
    Vector2 posMaxRange, // expects max range for both xy values
    Vector2 velocityMaxRange, // idem
    float radiusMaxRange
) {
    static int entity = 0;
    // Generating distributions for all the values
    std::uniform_int_distribution<int> posDistX(0, posMaxRange.x);
    std::uniform_int_distribution<int> posDistY(0, posMaxRange.y);
    std::uniform_real_distribution<float> velocityDistX(-velocityMaxRange.x, velocityMaxRange.x);
    std::uniform_real_distribution<float> velocityDistY(-velocityMaxRange.y, velocityMaxRange.y);
    std::uniform_int_distribution<int> radDist(1, radiusMaxRange);
    //assigning them a random value
    Vector2 position {
    static_cast<float>(posDistX(generator)),
    static_cast<float>(posDistY(generator))
    };
    Vector2 velocity {
    static_cast<float>(velocityDistX(generator)),
    static_cast<float>(velocityDistY(generator))
    };
    float radius = static_cast<float>(radDist(generator));
    positionStorage.add(entity, position);
    velocityStorage.add(entity, velocity);
    radiusStorage.add(entity, radius);
    entity++;
}
int main() {
    std::random_device rd; //getting random seed from hardware
    std::mt19937 gen(rd()); //each time I call gen() it gives me the next generated number and the machine updates it's state
    InitWindow(800, 600, "ECS Test");
    SetTargetFPS(60);
    ComponentStorage<Vector2> PositionStorage;
    
    ComponentStorage<Vector2> VelocityStorage;
    
    ComponentStorage<float> RadiusStorage;
    
    for (size_t i {0}; i < 20; i++) {
        SpawnBall(
            PositionStorage, VelocityStorage, RadiusStorage, gen, //storages and generator
            {static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())}, // position
            {5.0f,5.0f}, 50.0f); // velocity and radius
    }
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