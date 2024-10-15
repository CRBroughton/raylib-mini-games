#include "include/raylib.h"
#include "include/raymath.h"

const int screenWidth = 800;
const int screenHeight = 800;

int main(void)
{

    InitWindow(screenWidth, screenHeight, "Phyllotaxis");
    SetTargetFPS(60);

    int n = 0;
    int c = 20;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        float angle = n * 137.5;
        float radius = c * sqrt(n);

        float x = radius * cos(angle) + screenWidth / 2;
        float y = radius * sin(angle) + screenHeight / 2;

        DrawEllipse(x, y, 8, 8, WHITE);
        n++;

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
