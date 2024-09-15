#include <raylib.h>
#include <iostream>
#include "include/simulation.hpp"
#include "include/menu.hpp"

int main(void) {
    Color BG_COLOR = {40, 40, 40, 255};

    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 600;
    const int cellSize = 8;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conways Game of Life");

    int FPS = 15;
    SetTargetFPS(FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, cellSize);
    Menu menu(&simulation);

    while (!WindowShouldClose())
    {

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / cellSize;
            int column = mousePosition.x / cellSize;
            simulation.ToggleCell(row, column);
        }


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

        if(IsKeyPressed(KEY_ENTER)) {
            menu.show = !menu.show;
        }

        simulation.Update();
        menu.Update(&simulation);

        BeginDrawing();
        ClearBackground(BG_COLOR);
        simulation.Draw();
        
        if(menu.show) {
            menu.Draw();
        }


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
