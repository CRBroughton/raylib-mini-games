#include <raylib.h>
#include <iostream>
#include <cstring>

int calculateState(int a, int b, int c) {
    if (a == 1 && b == 1 && c == 1) return 1;
    if (a == 1 && b == 1 && c == 0) return 0;
    if (a == 1 && b == 0 && c == 1) return 1;
    if (a == 1 && b == 0 && c == 0) return 1;
    if (a == 0 && b == 1 && c == 1) return 0;
    if (a == 0 && b == 1 && c == 0) return 0;
    if (a == 0 && b == 0 && c == 1) return 1;
    if (a == 0 && b == 0 && c == 0) return 0;
}

int main(void) {
    Color BG_COLOR = {40, 40, 40, 255};

    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 400;
    const int cellSize = 40;
    int cells[10] = {1,0,0,1,0,1,0,1,1,0};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Elementary Automata");

    int FPS = 15;
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BG_COLOR);
        for (int i = 0; i < 10; ++i) {
            int x = i * cellSize;
            int y = 0;

            const int borderWidth = 1;
            DrawRectangle(x - borderWidth, y - borderWidth, cellSize + 2 * borderWidth, cellSize + 2 * borderWidth, BLACK);
            if (cells[i] == 1) {
                DrawRectangle(x, y, cellSize, cellSize, BLACK);
            } else {
                DrawRectangle(x, y, cellSize, cellSize, WHITE);
            }
        }

        int nextCells[10] = {0,0,0,0,0,0,0,0,0,0};
        nextCells[0] = cells[0];
        nextCells[10 - 1] = cells[10 - 1];
        for (int i = 1; i < 10 - 1; ++i) {
            int left = cells[i - 1];
            int right = cells[i + 1];
            int state = cells[i];
            int newState = calculateState(left, state, right);
            nextCells[i] = newState;

            // copy
        };
        std::memcpy(cells, nextCells, sizeof(cells));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
