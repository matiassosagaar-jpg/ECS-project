#include <MovementSystem.hpp>
#include <raymath.h>
namespace MovementSystem {
    void ApplyVelocity(const ComponentStorage<Vector2>& velocity, ComponentStorage<Vector2>& position) {
        // I'm iteratig over entities with velocities because I assume they're going to be less than
        // entities with positions
        for (const int entity : velocity.entities) {
            if (position.has(entity)) // just in case, so we do not try to modify a position of an entity without velocity
                position.component[position.entityToIndex[entity]] += velocity.component[(*velocity.entityToIndex.find(entity)).second];
        }
    }
}