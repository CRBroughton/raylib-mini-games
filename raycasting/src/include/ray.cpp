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

        bool cast(Boundary wall) const {
            const int x1 = wall.start.x;
            const int y1 = wall.start.y;
            const int x2 = wall.end.x;
            const int y2 = wall.end.y;

            const int x3 = position.x;
            const int y3 = position.y;
            const int x4 = position.x + direction.x;
            const int y4 = position.y + direction.y;

            const int denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
            if (denominator == 0) {
                return false;
            };

            const int t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
            const int u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;
            if (t > 0 && t < 1 && u > 0) {
                return true;
            } else {
                return false;
            }

        }

    private:
};