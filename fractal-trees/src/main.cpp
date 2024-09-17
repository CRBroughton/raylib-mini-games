#include <raylib.h>
#include <iostream>

int main(void) {
    Color BG_COLOR = {40, 40, 40, 255};

    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 400;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Fractal Trees");

    int FPS = 15;
    int lineLength = 100;
    SetTargetFPS(FPS);


    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BG_COLOR);

        DrawLine(WINDOW_WIDTH / 2, WINDOW_HEIGHT, WINDOW_WIDTH / 2, WINDOW_HEIGHT - lineLength, {255, 255, 255, 255});

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
