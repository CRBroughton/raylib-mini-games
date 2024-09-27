#pragma once
#include "raylib.h"
#include "ray.cpp"
#include "boundary.cpp"
#include <vector>
#include <cmath>
#include <iostream>

float radians(float degrees)
{
    return degrees * DEG2RAD;
}

class Particle
{
public:
    Vector2 position;
    std::vector<CustomRay> rays;

    Particle(Vector2 position)
    {
        this->position = position;
        generateRays();
    }

    void generateRays()
    {
        for (size_t angle = 0; angle < 360; angle += 10)
        {
            CustomRay ray(position, radians(angle));
            rays.push_back(ray);
        }
    }

    void look(Boundary wall)
    {
        for (CustomRay &ray : rays)
        {
            ray.position = this->position;
            Vector2 point = ray.Cast(wall);
            if (point.x && point.y)
            {
                DrawLineV(this->position, point, BLUE);
            }
        };
    }

    void show()
    {
        DrawEllipse(this->position.x, this->position.y, 4, 4, BLACK);
        for (const CustomRay &ray : rays)
        {
            ray.Draw();
        }
    }

    void update(Vector2 position)
    {
        this->position = position;
    }
};