#include "include/raylib.h"

const int screenWidth = 400;
const int screenHeight = 400;

int main(void)
{

    InitWindow(screenWidth, screenHeight, "Phyllotaxis");
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
