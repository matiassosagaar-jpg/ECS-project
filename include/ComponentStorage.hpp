#pragma once
#include <vector>
#include <raylib.h>
#include <unordered_map>
#include <cassert>
template <typename T>
class ComponentStorage {
public:
    std::vector<int> entities; // the elements of components have a 1-1 association with the ones in component
    std::vector<T> component;
    std::unordered_map<int, size_t> entityToIndex; // maps the entitys with the index they have in the entities vector
public:
    void RemoveComponent(int entity);

    void add(int entity,const T& newT);

    bool has(int entity) const;

    T& get(int entity);
    const T& get(int entity) const;
};
//Implementation
template <typename T>
void ComponentStorage<T>::RemoveComponent(int entity) {
    assert(!this->has(entity));
    size_t indexOfEntity = entityToIndex[entity];
    size_t lastIndex = entities.size() - 1;
    int lastEntity = entities[lastIndex];
    if (indexOfEntity != lastIndex) { // if I want to eliminate the last entity, I skip the process and just pop the vectors and erase the entity from the map
        entities[indexOfEntity] = lastEntity; // overwriting the current entity with the last one
        component[indexOfEntity] = component[lastIndex]; // same but with the components
        entityToIndex[lastEntity] = indexOfEntity; //Now the last entity needs to be related to index the erased entity had
    }
    entities.pop_back(); // Deleting the last (already deleted element) form both vectors
    component.pop_back();
    entityToIndex.erase(entity); // Removing entity from the map
}
template <typename T>
void ComponentStorage<T>::add(int entity, const T& newT) {
        if (this->has(entity)) { // If it's already among the entities that have this component
            component[entityToIndex[entity]] = newT; // We'll just overwrite it's component
        } else { // if not, then it'll push both arguments to the back of both vectors
            entities.push_back(entity); 
            component.push_back(newT);
            entityToIndex[entity] = std::size(entities) -1; // adding entity -> index connection for the new entity
        }
    }
template <typename T>
bool ComponentStorage<T>::has(int entity) const {
        return entityToIndex.find(entity) != entityToIndex.end();
    }
template <typename T>
T& ComponentStorage<T>::get(int entity){
    assert(this->has(entity)); // shut ups the programm if entity not found
    return component[entityToIndex.find(entity)->second]; // using find, [] is a non-const operator for the map
    
}
template <typename T>
const T& ComponentStorage<T>::get(int entity) const{
    assert(this->has(entity)); // shut ups the programm if entity not found
    return component[entityToIndex.find(entity)->second]; // using find, [] is a non-const operator for the map
}