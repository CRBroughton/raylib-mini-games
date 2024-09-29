#pragma once
#include "raylib.h"
#include <cmath>
#include <vector>
#include <rlgl.h>

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
        for (int x = -1; x < 2; x++)
        {
            for (int y = -1; y < 2; y++)
            {
                for (int z = -1; z < 2; z++)
                {

                    int sum = abs(x) + abs(y) + abs(z);
                    if (sum > 1)
                    {

                        float newSize = this->size / 3.0f;
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
        }
        return boxes;
    }

    void show(Model cubeModel)
    {
        DrawModel(cubeModel, this->position, this->size, WHITE);
    }
};