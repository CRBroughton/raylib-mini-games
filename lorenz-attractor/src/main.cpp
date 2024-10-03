#include "include/raylib.h"
#include "include/box.cpp"
#include <cmath>
#include <vector>

const int screenWidth = 800;
const int screenHeight = 800;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Lorenz Attractor");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
