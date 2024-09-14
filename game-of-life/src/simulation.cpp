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
