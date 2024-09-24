#pragma once
#include "raylib.h"
#include "boundary.cpp"

class CustomRay {
    public:
        Vector2 position;
        Vector2 direction;
        CustomRay(Vector2 start) {
            position = start;
            direction = { 1, 0 };
        };

        void Draw() const {
            DrawLineV(position, {position.x + 10, position.y}, BLUE);
        }

        bool Cast(Boundary wall) {
            float x1 = wall.start.x;
            float y1 = wall.start.y;
            float x2 = wall.end.x;
            float y2 = wall.end.y;

            float x3 = position.x;
            float y3 = position.y;
            float x4 = position.x + direction.x;
            float y4 = position.y + direction.y;

            float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
            if (denominator == 0) {
                return false;
            };

            // position along the wall where the intersection occurs
            float wallIntersectionFactor = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
            // how far along the ray the intersection occurs
            float rayIntersectionFactor = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

            return (wallIntersectionFactor >= 0 && wallIntersectionFactor <= 1 && rayIntersectionFactor >= 0);

        }

    private:
};
