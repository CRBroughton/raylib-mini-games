#pragma once
#include "raylib.h"
#include "boundary.cpp"
#include <cmath>

void Vector2Normalize(Vector2 *v)
{
    float length = sqrtf(v->x * v->x + v->y * v->y);
    if (length != 0)
    {
        v->x /= length;
        v->y /= length;
    }
}

class CustomRay
{
public:
    Vector2 position;
    Vector2 direction;
    CustomRay(Vector2 start)
    {
        position = start;
        direction = {1, 0};
    };

    void Draw() const
    {
        Vector2 rayEndPosition = {position.x + direction.x * 1000, position.y + direction.y * 1000};
        DrawLineV(position, rayEndPosition, BLUE);
    }

    void SetDirection(float x, float y)
    {
        this->direction.x = x - this->position.x;
        this->direction.y = y - this->position.y;
        Vector2Normalize(&direction);
    }

    Vector2 Cast(Boundary wall)
    {
        float x1 = wall.start.x;
        float y1 = wall.start.y;
        float x2 = wall.end.x;
        float y2 = wall.end.y;

        float x3 = position.x;
        float y3 = position.y;
        float x4 = position.x + direction.x;
        float y4 = position.y + direction.y;

        float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (denominator == 0)
        {
            return {0, 0};
        };

        // position along the wall where the intersection occurs
        float wallIntersectionFactor = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
        // how far along the ray the intersection occurs
        float rayIntersectionFactor = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

        if (wallIntersectionFactor >= 0 && wallIntersectionFactor <= 1 && rayIntersectionFactor >= 0)
        {
            Vector2 intersectionPoint = {
                x1 + wallIntersectionFactor * (x2 - x1),
                y1 + wallIntersectionFactor * (y2 - y1)};
            return intersectionPoint;
        }
        else
        {
            return {0, 0};
        }
    }

private:
};
