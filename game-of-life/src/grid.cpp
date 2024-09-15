#include <raylib.h>
#include <iostream>
#include "include/grid.hpp"
void Grid::Draw() {
    // Look through every cell
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Cell cell = cells[row][column];
            Color color;
            if (cell.isAlive()) {
                color = {66,92,94, 255};
            } else {
                if (cell.getHealth() == 0) {
                    color = {40, 40, 40, 255};
                } else if (cell.getHealth() == 1) {
                    color = {78,0,106, 255}; 
                } 
            }
            int centerX = column * cellSize + cellSize / 2;
            int centerY = row * cellSize + cellSize / 2;
            DrawCircle(centerX, centerY, cellSize / 2 - 1, color);
        }
    }
}


void Grid::SetValue(int row, int column, int value) {
    if(isWithinBounds(row, column)) {
        cells[row][column].setAlive(value);
    }
}

int Grid::Getvalue(int row, int column) {
    if(isWithinBounds(row, column)) {
       return cells[row][column].isAlive();
    }
    return 0;
}

void Grid::FillRandom() {
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            int randomValue = GetRandomValue(0, 4);
            cells[row][column].setAlive((randomValue == 4) ? 1 : 0);
        }
    }
}

void Grid::Clear() {
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            cells[row][column].resetHealth();
            cells[row][column].setAlive(false);
        }
    }
}

void Grid::ToggleCell(int row, int column) {
    if(isWithinBounds(row, column)) {
        cells[row][column].setAlive(!cells[row][column].isAlive());
    }
}

bool Grid::isWithinBounds(int row, int column) {
    if(row >= 0 && row < rows && column >= 0 && column < columns) {
        return true;
    }
    return false;
}
