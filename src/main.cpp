#include <raylib.h>
#include <iostream>
#include "sim.hpp"

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 800;
    const int CELL_SIZE = 4;
    int FPS = 12;
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Sim sim(WINDOW_WIDTH, WINDOW_HEIGHT,CELL_SIZE);
    // sim.SetCellValue(5,29,1);
    // sim.SetCellValue(6,0,1);
    // sim.SetCellValue(5,0,1);
    // sim.SetCellValue(4,0,1);

    //std::cout << sim.CountLiveNeighbors(5,29) << std::endl;

    //Sim Loop
    while(WindowShouldClose() == false) {
        //1. Event Handling

        //2. Updating State
        sim.Update();

        //3. Drawing
        BeginDrawing();
        ClearBackground(GREY);
        sim.Draw();
        EndDrawing();
    }


    CloseWindow();
}