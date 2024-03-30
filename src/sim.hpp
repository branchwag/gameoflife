#pragma once
#include "grid.hpp"

class Sim{
    public:
        Sim(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize) {grid.FillRandom();};
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbors(int row, int column);
        void Update();
    private:
        Grid grid;
        Grid tempGrid;
};