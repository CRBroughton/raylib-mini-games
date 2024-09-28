#pragma once
#include "raylib.h"
#include "ray.cpp"
#include "boundary.cpp"
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>

float radians(float degrees)
{
    return degrees * DEG2RAD;
}

// Distance between two vectors
float VectorDist(Vector2 v1, Vector2 v2)
{
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    return sqrtf(dx * dx + dy * dy);
}

float min(float a, float b)
{
    return (a < b) ? a : b;
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
        for (size_t angle = 0; angle < 360; angle += 1)
        {
            CustomRay ray(position, radians(angle));
            rays.push_back(ray);
        }
    }

    void look(std::vector<Boundary> walls)
    {
        for (CustomRay &ray : rays)
        {
            Vector2 closest = {0, 0};
            // positive infinity
            float record = std::numeric_limits<float>::infinity();
            for (Boundary &wall : walls)
            {

                ray.position = this->position;
                Vector2 point = ray.Cast(wall);

                if (point.x != 0 && point.y != 0)
                {
                    float distance = VectorDist(this->position, point);
                    if (distance < record)
                    {
                        record = distance;
                        closest = point;
                    }
                }
            }
            if (closest.x != 0 && closest.y != 0)
            {
                DrawLineV(this->position, closest, {255, 255, 255, 100});
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