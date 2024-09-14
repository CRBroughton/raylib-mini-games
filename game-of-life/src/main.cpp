#include <raylib.h>

int main(void)
{
    Color BG_COLOR = {29, 29, 29, 255};

    const int screenWidth = 750;
    const int screenHeight = 750;
    const int cellSize = 25;

    InitWindow(screenWidth, screenHeight, "Conways Game of Life");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BG_COLOR);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
