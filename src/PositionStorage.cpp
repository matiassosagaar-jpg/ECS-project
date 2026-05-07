#include "PositionStorage.hpp"

void PositionStorage::RemoveComponent(int entity) {
    assert(!this->has(entity));
    size_t indexOfEntity = entityToIndex[entity];
    size_t lastIndex = entities.size() - 1;
    int lastEntity = entities[lastIndex];
    if (indexOfEntity != lastIndex) { // si quiero eliminar la ultima entidad del vector, me salteo todo el rpoceso
        entities[indexOfEntity] = lastEntity; // overwriting the current entity with the last one
        position[indexOfEntity] = position[lastIndex]; // same but with the components
        entityToIndex[lastEntity] = indexOfEntity; //Now the last entity needs to be related to index the erased entity had
    }
    entities.pop_back(); // Deleting the last (already deleted element) form both vectors
    position.pop_back();
    entityToIndex.erase(entity); // Removing entity from the map
}

void PositionStorage::add(int entity, Vector2 newPosition) {
        if (this->has(entity)) { // If it's already among the entities that have this component
            position[entityToIndex[entity]] = newPosition; // We'll just overwrite it's component
        } else { // if not, then it'll push both arguments to the back of both vectors
            entities.push_back(entity); 
            position.push_back(newPosition);
            entityToIndex[entity] = std::size(entities) -1; // adding entity -> index connection for the new entity
        }
    }

bool PositionStorage::has(int entity) const {
        return entityToIndex.find(entity) != entityToIndex.end();
    }

const Vector2& PositionStorage::get(int entity) const{
    assert(this->has(entity)); // shut ups the programm if entity not found
    return position[entityToIndex.find(entity)->second]; // using find, [] is a non-const operator for the map
    
}