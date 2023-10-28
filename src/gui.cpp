#define RAYGUI_IMPLEMENTATION

#include <iostream>
#include <raylib.h>
#include "raygui.h"
#include "gui.h"

using namespace std;

void GUI::drawStackUI(int height, int width)
{
    float h = height, w = width;

    GuiGroupBox(Rectangle{w - 200, 20, 190, h - 40}, "Stack Functions");
    GuiGroupBox(Rectangle{10, 20, w - 220, h - 200}, "Visualization");
    GuiGroupBox(Rectangle{10, h - 165, w - 220, h - 455}, "Logs");

    GuiTextBox(Rectangle{w - 190, 35, 170, 35}, "10", 10, true);
    GuiButton(Rectangle{w - 190, 80, 170, 35}, "Push");
    GuiButton(Rectangle{w - 190, 125, 170, 35}, "Pop");
}