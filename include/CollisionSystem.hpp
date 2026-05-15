#pragma once
#include <ComponentStorage.hpp>

namespace CollisionSystem {
    bool CheckEntityCollision_Ball(
    int lEntity, int rEntity,
    const ComponentStorage<Vector2>& positionStorage,
    const ComponentStorage<float>& radiusStorage
    );

    template <typename Func>
    void ForEachBallCollision(
        const ComponentStorage<Vector2>& positionStorage,
        const ComponentStorage<float>& radiusStorage,
        Func func // expects a lambda expression that will catch the context(storages) by ref and 2 entities as arguments
    );

    void HighlightCollisions_Ball(
        const ComponentStorage<Vector2>& positionStorage,
        const ComponentStorage<float>& radiusStorage, // only read storages
        ComponentStorage<Color>& overlayStorage,
        Color highLightColor // color of the highlight
    );

    void SwapVelocityInCollision_Ball(
        const ComponentStorage<Vector2>& positionStorage,
        const ComponentStorage<float>& radiusStorage, // only read storages
        ComponentStorage<Vector2>& velocityStorage
    );
    
}

