#pragma once
#include "raylib.h"

class Boundary
{
public:
    Vector2 start;
    Vector2 end;

    Boundary(Vector2 startPoint, Vector2 endPoint)
    {
        start = startPoint;
        end = endPoint;
    };

    void Draw() const
    {
        DrawLineV(start, end, DARKGREEN);
    }

private:
};