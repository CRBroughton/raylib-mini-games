#include <raylib.h>
#include <iostream>
#include <simulation.hpp>

int main(void) {
    Color BG_COLOR = {29, 29, 29, 255};

    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int cellSize = 25;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conways Game of Life");

    int FPS = 25;
    SetTargetFPS(FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, cellSize);

    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_SPACE)) {
            simulation.Toggle();
        }
        else if(IsKeyDown(KEY_F)) {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if(IsKeyDown(KEY_D)) {
            FPS -= 2;
            SetTargetFPS(FPS);
        }
        else if(IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }
        else if(IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(BG_COLOR);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
