#pragma once
#include <raylib.h>
#include <random>
#include <ComponentStorage.hpp>

namespace EntitySpawner {
    void SpawnBall(
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
    );
}