#define RAYGUI_IMPLEMENTATION

#include <iostream>
#include <functional>
#include <raylib.h>
#include "raygui.h"
#include "gui.h"
#include "stack.h"

using namespace std;

char dataInput[1024] = "10";

void GUI::drawStackUI(int height, int width)
{
    float h = height, w = width;

    GuiGroupBox(Rectangle{w - 200, 20, 190, h - 40}, "Stack Functions");
    GuiGroupBox(Rectangle{10, 20, w - 220, h - 200}, "Visualization");
    GuiGroupBox(Rectangle{10, h - 165, w - 220, h - 455}, "Logs");

    GuiTextBox(Rectangle{w - 190, 35, 170, 35}, dataInput, 1024, true);

    if (GuiButton(Rectangle{w - 190, 80, 170, 35}, "Push"))
    {
        Stack::push(atoi(dataInput));
    }
    if (GuiButton(Rectangle{w - 190, 125, 170, 35}, "Pop"))
    {
        if (Stack::getSize() > 0)
            Stack::pop();
    }
}