#pragma once
#include <vector>
#include "cell.hpp"

class Grid {
    public:
        Grid(int width, int height, int cellSize)
        : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<Cell>(columns)) {};
        void Draw();
        void SetValue(int row, int column, int value);
        int Getvalue(int row, int column);
        int GetRows() { return rows;};
        int GetColumns() { return columns;};
        void FillRandom();
        void Clear();
        void ToggleCell(int row, int column);
    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<Cell>> cells;
        bool isWithinBounds(int row, int column);
};