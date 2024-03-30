#pragma once
#include "grid.hpp"

class Sim{
    public:
        Sim(int width, int height, int cellSize)
        : grid(width, height, cellSize) {};
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbors(int row, int column);
    private:
        Grid grid;
};