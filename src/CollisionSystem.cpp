#include <CollisionSystem.hpp>
#include <stdexcept>

bool CollisionSystem::CheckEntityCollision_Ball( //contract: Entities must have position and radius components
    int lEntity, int rEntity, //Entities for collitionCheck
    const ComponentStorage<Vector2>& positionStorage, // storages to gather info from 
    const ComponentStorage<float>& radiusStorage
) {
    if (!positionStorage.has(lEntity) || !positionStorage.has(rEntity) || //if any components of the compared entitys are missing, raise an exception
    !radiusStorage.has(lEntity) || !radiusStorage.has(rEntity)) 
        throw std::invalid_argument("Invalid entites don't qualify as Ball objects"); // Using exception in development phase, will be an assert later
    return CheckCollisionCircles(
            positionStorage.get(lEntity), radiusStorage.get(lEntity), // lEntity components
            positionStorage.get(rEntity), radiusStorage.get(rEntity)  // rEntity components
        );
}

void CollisionSystem::HighlightCollisions_Ball(
        const ComponentStorage<Vector2>& positionStorage,
        const ComponentStorage<float>& radiusStorage, // only read storages
        ComponentStorage<Color>& overlayStorage,
        ComponentStorage<Color>& colorStorage, // storage we'll write on
        Color highLightColor // colo{r of the highlight
    ) {
        for (size_t i {0}; i < positionStorage.entities.size(); i++) {
            if (
                !radiusStorage.has(positionStorage.entities[i]) || 
                !overlayStorage.has(positionStorage.entities[i]) ||
                !colorStorage.has(positionStorage.entities[i])) {// Check for missing components
                    throw std::invalid_argument("Invalid entities don't qualify as Ball objects.");
            }
            for (size_t j {i + 1}; j < positionStorage.entities.size(); j++) { // j = i+1 to not compare equal entitys
                if (
                !radiusStorage.has(positionStorage.entities[j]) || 
                !overlayStorage.has(positionStorage.entities[j]) ||
                !colorStorage.has(positionStorage.entities[j])) {// Check for missing components
                    throw std::invalid_argument("Invalid entities don't qualify as Ball objects.");
            }
                if (CollisionSystem::CheckEntityCollision_Ball(
                    positionStorage.entities[i], positionStorage.entities[j], //entities to compare
                    positionStorage, radiusStorage // Storages needed to check collisions                
                    )
                ) {
                    overlayStorage.get(positionStorage.entities[i]) = highLightColor; // if they're coliding, we'll highlight them
                    overlayStorage.get(positionStorage.entities[j]) = highLightColor;
                }
            }
        }
    }