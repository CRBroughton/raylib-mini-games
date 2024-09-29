#pragma once
#include "raylib.h"
#include <cmath>
#include <vector>

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

    std::vector<Box> generate()
    {
        std::vector<Box> boxes;
        for (size_t x = -1; x < 2; x++)
        {
            for (size_t y = -1; y < 2; y++)
            {
                for (size_t z = -1; z < 2; z++)
                {
                    float newSize = this->size / 3;
                    Box box({
                                this->position.x + x * newSize,
                                this->position.y + y * newSize,
                                this->position.z + z * newSize,
                            },
                            newSize);
                    boxes.push_back(box);
                }
            }
        }
        return boxes;
    }

    void show()
    {
        // DrawCube(this->position, this->size, this->size, this->size, RED);
        DrawCubeWires(this->position, this->size, this->size, this->size, MAROON);
    }
};