#include <raylib.h>
#include <iostream>
#include <simulation.hpp>

int main(void) {
    Color BG_COLOR = {29, 29, 29, 255};

    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;
    const int cellSize = 4;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conways Game of Life");
    SetTargetFPS(25);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, cellSize);

    while (!WindowShouldClose())
    {

        simulation.Update();

        BeginDrawing();
        ClearBackground(BG_COLOR);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
