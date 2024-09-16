#include <raylib.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

int calculateState(std::vector<int> ruleset, int a, int b, int c) {
    int value = (a << 2) | (b << 1) | c; 
    return ruleset[7 - value];
}

void setup(std::vector<int>& cells, int cellSize) {
    int total = 810 / cellSize;
    cells.resize(total);
    for (int i = 0; i < total; i++) {
        // cells[i] = rand() % 2;
        cells[i] = 0;
    }
    cells[floor(total/2)] = 1;
}

int main(void) {
    std::vector<int> ruleset = {1, 0, 1, 1, 0, 1, 1, 0};
    Color BG_COLOR = {40, 40, 40, 255};

    const int WINDOW_WIDTH = 810;
    const int WINDOW_HEIGHT = 810;
    const int cellSize = 10 ;
    int y = 0;
    std::vector<int> cells;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Elementary Automata");

    int FPS = 15;
    SetTargetFPS(FPS);
    setup(cells, cellSize);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // Draw the current cells
        for (int i = 0; i < cells.size(); i++) {
            int x = i * cellSize;
            const int borderWidth = 1;
            DrawRectangle(x - borderWidth, y - borderWidth, cellSize + 2 * borderWidth, cellSize + 2 * borderWidth, BLACK);
            if (cells[i] == 1) {
                DrawRectangle(x, y, cellSize, cellSize, BLACK);
            } else {
                DrawRectangle(x, y, cellSize, cellSize, WHITE);
            }
        }

        y += cellSize;

        // Create a nextCells vector to hold the new states
        std::vector<int> nextCells(cells.size(), 0); // Initialize

        // First and last cell (boundaries)
        nextCells[0] = cells[0];
        nextCells[cells.size() - 1] = cells[cells.size() - 1];

        for (int i = 1; i < cells.size() - 1; i++) {
            int left = cells[i - 1];
            int right = cells[i + 1];
            int state = cells[i];
            int newState = calculateState(ruleset, left, state, right);
            nextCells[i] = newState;
        }

        // cpy
        cells = nextCells;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
 