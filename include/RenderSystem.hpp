#pragma once
#include <vector>
/* 
The purpose of this system Is to ONLY DRAW in screen
It does NOT modify values in storage
*/
#include <ComponentStorage.hpp>
/* 
Since the Render System Only Needs a position to draw,
it makes sense it expects a Vector2 and not any other
kind of type
*/
namespace RenderSystem {
    void DrawEntities(
        const ComponentStorage<Vector2>& position,
        const ComponentStorage<float>& radius,
        const ComponentStorage<Color>& color
    );
}