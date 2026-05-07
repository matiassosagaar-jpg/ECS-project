#pragma once
#include <vector>
#include <raylib.h>
#include <utility>
#include <unordered_map>
#include <cassert>
class PositionStorage {
public:
    std::vector<int> entities; // the elements of components have a 1-1 association with the ones in component
    std::vector<Vector2> position;
    std::unordered_map<int, size_t> entityToIndex; // maps the entitys with the index they have in the entities vector
public:
    void RemoveComponent(int entity);

    void add(int entity, Vector2 newPosition);

    bool has(int entity) const;

    const Vector2& get(int entity) const;
};