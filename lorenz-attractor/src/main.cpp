#include "include/raylib.h"

const int screenWidth = 800;
const int screenHeight = 800;

float x = 00.1;
float y = 0;
float z = 0;

const float a = 10;
const float b = 28;
const float c = 8.0 / 3.0;
const float scale = 10.0f;
int main(void)
{
    InitWindow(screenWidth, screenHeight, "Lorenz Attractor");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        float dt = 0.01;
        float dx = (a * (y - x)) * dt;
        float dy = (x * (b - z) - y) * dt;
        float dz = (x * y - c * z) * dt;
        x = x + dx;
        y = y + dy;
        z = z + dz;

        int screenX = screenWidth / 2 + x * scale;
        int screenY = screenHeight / 2 + y * scale;
        DrawPixel(screenX, screenY, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
