#include <raylib.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hello, World!");
    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello, World!", screenWidth / 2 - 60, screenHeight / 2 - 20, 40, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
