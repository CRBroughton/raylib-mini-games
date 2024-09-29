#pragma once
#include "raylib.h"

class Box
{
public:
    Vector3 position;
    float size;

    Box(Vector3 position, float size)
    {
        this->position = position;
        this->size = size;
    }

    void show()
    {
        // DrawCube(this->position, this->size, this->size, this->size, RED);
        DrawCubeWires(this->position, this->size, this->size, this->size, MAROON);
    }
};