#include "EntitySpawner.hpp"

void EntitySpawner::SpawnBall(
    ComponentStorage<Vector2>& positionStorage,
    ComponentStorage<Vector2>& velocityStorage,
    ComponentStorage<float>& radiusStorage,
    ComponentStorage<Color>& colorStorage,
    ComponentStorage<Color>& overlayStorage,
    std::mt19937& generator, // passing the generator by reference
    Vector2 posMaxRange, // expects max range for both xy values
    Vector2 velocityMaxRange, // idem
    float radiusMaxRange,
    Color color
) {
    static int entity = 0;
    // Generating distributions for all the values
    std::uniform_int_distribution<int> posDistX(0, posMaxRange.x);
    std::uniform_int_distribution<int> posDistY(0, posMaxRange.y);
    std::uniform_real_distribution<float> velocityDistX(-velocityMaxRange.x, velocityMaxRange.x);
    std::uniform_real_distribution<float> velocityDistY(-velocityMaxRange.y, velocityMaxRange.y);
    std::uniform_int_distribution<int> radDist(1, radiusMaxRange);
    //assigning them a random values
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
    colorStorage.add(entity, color);
    overlayStorage.add(entity, BLANK);
    entity++;
}