#include <raylib.h>
#include <iostream>
#include <simulation.hpp>

int main(void) {
    Color BG_COLOR = {29, 29, 29, 255};

    const int screenWidth = 750;
    const int screenHeight = 750;
    const int cellSize = 25;

    InitWindow(screenWidth, screenHeight, "Conways Game of Life");
    SetTargetFPS(60);

    Simulation simulation(screenWidth, screenHeight, cellSize);
    simulation.SetCellValue(3, 4, 1);
    simulation.SetCellValue(3, 5, 1);
    simulation.SetCellValue(4, 5, 1);
    simulation.SetCellValue(2, 5, 1);

    std::cout << simulation.CountLiveNeighbours(3, 4) << std::endl;


    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BG_COLOR);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
