#include <raylib.h>
#include "grid.hpp"

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Grid grid{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    grid.SetValue(0,0,1);

    //Sim Loop
    while(WindowShouldClose() == false) {
        //1. Event Handling

        //2. Updating State

        //3. Drawing
        BeginDrawing();
        ClearBackground(GREY);
        grid.Draw();
        EndDrawing();
    }


    CloseWindow();
}