#pragma once
#include "grid.hpp"
#include <raylib.h>

class Simulation {
    public:
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), run(false), tempGrid(width, height, cellSize){
            grid.FillRandom();
        };
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbours(int row, int columns);
        void Update();
        bool isRunning() { return run; };
        void Toggle() {
             run = !run;
             setTitle();
        };
    private:
        Grid grid;
        Grid tempGrid;
        bool run = false;
        void setTitle() {
            if (run) {
                SetWindowTitle("Game of Life is running...");
            } else {
                SetWindowTitle("Game of Life stopped...");
            }
        }
};