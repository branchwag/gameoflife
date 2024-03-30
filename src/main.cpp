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
    Sim sim{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    // sim.SetCellValue(5,29,1);
    // sim.SetCellValue(6,0,1);
    // sim.SetCellValue(5,0,1);
    // sim.SetCellValue(4,0,1);

    //std::cout << sim.CountLiveNeighbors(5,29) << std::endl;

    //Sim Loop
    while(WindowShouldClose() == false) {
        //1. Event Handling
        //My mouse was doubleclicking instead of single clicking and start failed with this, so omitting this control for now.
        // if(IsKeyPressed(KEY_A)){
        //     Vector2 mousePosition = GetMousePosition();
        //     int row = mousePosition.y / CELL_SIZE;
        //     int column = mousePosition.x / CELL_SIZE;
        //     // std::cout << mousePosition.y << std::endl;
        //     // std::cout << mousePosition.x << std::endl;
        //     //std::cout << row << std::endl;
        //     //std::cout << column << std::endl;
        //     sim.ToggleCell(row, column);
        // }
        if(IsKeyPressed(KEY_ENTER)){
            sim.Start();
            SetWindowTitle("Game of Life is running...");
        }
        else if(IsKeyPressed(KEY_SPACE)){
            sim.Stop();
            SetWindowTitle("Game of Life stopped.");
        }
        else if(IsKeyPressed(KEY_F)){
            FPS +=2;
            SetTargetFPS(FPS);
        }
        else if(IsKeyPressed(KEY_S)){
            if(FPS > 5){
            FPS -=2;
            SetTargetFPS(FPS);
            }
        }
        else if(IsKeyPressed(KEY_R)){
            sim.CreateRandomState();
        }
        else if(IsKeyPressed(KEY_C)){
            sim.ClearGrid();
        }

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