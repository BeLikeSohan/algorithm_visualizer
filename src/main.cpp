#include <iostream>
#include <raylib.h>
#include "raygui.h"
#include "stack.h"
#include "gui.h"
#include "bubble_sort.h"

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;

GUI gui = GUI();

int currentSceneId = 1;

void drawStackScene()
{
    gui.drawStackUI(screenHeight, screenWidth);

    Stack::draw(screenHeight, screenWidth);
}

void drawSplashScene()
{
    DrawText("Algorithm Visualizer", 20, 20, 50, WHITE);
    DrawText("Version: 1.0", 20, 70, 30, WHITE);
    DrawText("Made by:", 20, 115, 20, WHITE);
    DrawText("Washiul Alam Sohan (@belikesohan)", 20, 140, 20, WHITE);
    DrawText("Marjan Haque Sumaiya (@mrjnhq)", 20, 165, 20, WHITE);

    if (GuiButton(Rectangle{screenWidth - 190, screenHeight - 60, 170, 35}, "Start"))
    {
        currentSceneId = 1;
    }
}

void drawMenuScene()
{
    DrawText("Select Algorithm", 20, 20, 50, WHITE);
    if (GuiButton(Rectangle{20, 90, 170, 35}, "Bubble Sort"))
    {
        currentSceneId = 3;
    }
    GuiButton(Rectangle{200, 90, 170, 35}, "Selection Sort");
    GuiButton(Rectangle{380, 90, 170, 35}, "Merge Sort");
    GuiButton(Rectangle{20, 135, 170, 35}, "Bubble Sort");
    GuiButton(Rectangle{200, 135, 170, 35}, "Selection Sort");
    GuiButton(Rectangle{380, 135, 170, 35}, "Merge Sort");
    GuiButton(Rectangle{20, 180, 170, 35}, "Bubble Sort");
    GuiButton(Rectangle{200, 180, 170, 35}, "Selection Sort");
    GuiButton(Rectangle{380, 180, 170, 35}, "Merge Sort");

    DrawText("Select Data Structure", 20, 250, 50, WHITE);
    if (GuiButton(Rectangle{20, 320, 170, 35}, "Stack"))
    {
        currentSceneId = 2;
    }

    GuiButton(Rectangle{200, 320, 170, 35}, "Queue");
    GuiButton(Rectangle{380, 320, 170, 35}, "Double Queue");
    GuiButton(Rectangle{20, 365, 170, 35}, "Tree");
    GuiButton(Rectangle{200, 365, 170, 35}, "Selection Sort");
    GuiButton(Rectangle{380, 365, 170, 35}, "Merge Sort");
    GuiButton(Rectangle{20, 410, 170, 35}, "Bubble Sort");
    GuiButton(Rectangle{200, 410, 170, 35}, "Selection Sort");
    GuiButton(Rectangle{380, 410, 170, 35}, "Merge Sort");
}

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    InitWindow(screenWidth, screenHeight, "Algorithm Visualizer");
    SetTargetFPS(30);

    BubbleSort::create(9);
    BubbleSort::insert(6);
    BubbleSort::insert(3);
    BubbleSort::insert(5);
    BubbleSort::insert(9);
    BubbleSort::insert(4);
    BubbleSort::insert(1);
    BubbleSort::insert(8);
    BubbleSort::insert(2);
    BubbleSort::insert(7);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(DARKBLUE);

        switch (currentSceneId)
        {
        case 0:
            drawSplashScene();
            break;
        case 1:
            drawMenuScene();
            break;
        case 2:
            drawStackScene();
            break;
        case 3:
            gui.drawBubbleSortUI(screenHeight, screenWidth);
            BubbleSort::draw(screenHeight, screenWidth);
            BubbleSort::drawSort(screenHeight, screenWidth);
            break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}