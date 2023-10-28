#include <iostream>
#include <raylib.h>
#include "stack.h"
#include "gui.h"

using namespace std;

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Algorithm Visualizer");
    SetTargetFPS(60);

    GUI gui = GUI();

    Stack stack = Stack();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);

        gui.drawStackUI(screenHeight, screenWidth);
        stack.draw(screenHeight, screenWidth);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}