#include <raylib.h>
#include <iostream>

int main(void) {
    Color BG_COLOR = {40, 40, 40, 255};

    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 400;
    const int cells[10] = {1,0,0,1,0,1,0,1,1,0};
    const int cellSize = 40;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conways Game of Life");

    int FPS = 15;
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BG_COLOR);
        for (int i = 0; i < 10; ++i) {
            int x = i * cellSize;
            int y = 0;
            if (cells[i] == 1) {
                DrawRectangle(x, y, cellSize, cellSize, BLACK);
            } else {
                DrawRectangle(x, y, cellSize, cellSize, WHITE);
            }
        }
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
