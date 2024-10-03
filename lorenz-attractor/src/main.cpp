#include "include/raylib.h"
#include "include/box.cpp"
#include <cmath>
#include <vector>

const int screenWidth = 800;
const int screenHeight = 800;

float x = 0;
float y = 0;
float z = 0;

const float a = 1;
const float b = 1;
const float c = 1;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Lorenz Attractor");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        float dx = a * (y - x);
        float dy = x * (b - z) - y;
        float dz = x * y - c * z;
        x = x + dx;
        y = y + dy;
        z = z + dz;

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
