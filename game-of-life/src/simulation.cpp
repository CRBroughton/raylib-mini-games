#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbours(int row, int column) {
    int liveNeighbours = 0;

    // Define the possible offsets
    std::vector<std::pair<int, int>> neighbourOffsets = {
        {-1, 0}, // Above
        {1, 0},  // Below
        {0, -1}, // Left
        {0, 1},  // Right
        {-1, -1},// Upper Left
        {-1, 1}, // Upper Right
        {1, -1}, // Lower Left
        {1, 1}   // Lower Right
    };

    // Iterate through the offsets & add up the amount of alive neighbours
    for(const auto& offset : neighbourOffsets) {
        int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetColumns();
        int neighbourColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();

        liveNeighbours += grid.Getvalue(neighbourRow, neighbourColumn);
    };

    return liveNeighbours;
}

void Simulation::Update() {
    if (isRunning()) {
        for(int row = 0; row < grid.GetRows(); row++) {
                for(int column = 0; column < grid.GetColumns(); column++) {
                    int liveNeighbours = CountLiveNeighbours(row, column);
                    int cellValue = grid.Getvalue(row, column);

                    if(cellValue == 1) {
                        // Overpopulation & Underpopulation
                        if(liveNeighbours > 3 || liveNeighbours < 2) {
                            tempGrid.SetValue(row, column, 0);
                        } else {
                            tempGrid.SetValue(row, column, 1);

                        }
                    } else {
                        // Stasis and Repopulation
                        if(liveNeighbours == 3) {
                            tempGrid.SetValue(row, column, 1);
                        } else {
                            tempGrid.SetValue(row, column, 0);
                        }
                    }

                }
            }
        grid = tempGrid;
    }
};
