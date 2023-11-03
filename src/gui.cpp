#define RAYGUI_IMPLEMENTATION

#include <iostream>
#include <functional>
#include <string.h>
#include <sstream>
#include <raylib.h>
#include "raygui.h"
#include "gui.h"
#include "stack.h"
#include "bubble_sort.h"

using namespace std;

char dataInput[1024] = "9";
char codes[1024];

char *stackPushCodeOnNull = "struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));\nstrcpy(newNode->data, %s);\nnewNode->next = NULL;\nstackHead = newNode;";
char *stackPushCode = "struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));\nstrcpy(newNode->data, %s);\nnewNode->next = stackHead;\nstackHead = newNode;";
char *stackPopCode = "struct Node *tempNode = stackHead;\nchar *data = stackHead->data;\nstackHead = stackHead->next;\nfree(tempNode);\nsize--;\nreturn data;";

void GUI::drawStackUI(int height, int width)
{
    float h = height, w = width;

    GuiGroupBox(Rectangle{w - 200, 20, 190, h - 40}, "Stack Functions");
    GuiGroupBox(Rectangle{10, 20, w - 220, h - 200}, "Visualization");
    GuiGroupBox(Rectangle{10, h - 165, w - 220, h - 455}, "Code Example");
    GuiTextBox(Rectangle{w - 190, 35, 170, 35}, dataInput, 1024, true);

    if (GuiButton(Rectangle{w - 190, 80, 170, 35}, "Push"))
    {
        if (Stack::getSize() == 0)
        {
            strcpy(codes, TextFormat(stackPushCodeOnNull, dataInput));
        }
        else
        {
            strcpy(codes, TextFormat(stackPushCode, dataInput));
        }

        Stack::push(dataInput);
    }
    if (GuiButton(Rectangle{w - 190, 125, 170, 35}, "Pop"))
    {
        if (Stack::getSize() > 0)
        {
            strcpy(codes, TextFormat(stackPopCode, dataInput));
            Stack::pop();
        }
    }

    DrawText(codes, 20, h - 155, 10, WHITE);
}

void GUI::drawBubbleSortUI(int height, int width)
{
    float h = height, w = width;

    GuiGroupBox(Rectangle{w - 200, 20, 190, h - 40}, "Array Functions");
    GuiGroupBox(Rectangle{10, 20, w - 220, h - 200}, "Visualization");
    GuiGroupBox(Rectangle{10, h - 165, w - 220, h - 455}, "Code Example");

    GuiTextBox(Rectangle{w - 190, 35, 170, 35}, dataInput, 1024, true);

    if (!array_created)
    {
        if (GuiButton(Rectangle{w - 190, 80, 170, 35}, "Create Array"))
        {
            BubbleSort::create(atoi(dataInput));
            array_created = true;
        }
    }
    else
    {
        if (GuiButton(Rectangle{w - 190, 80, 170, 35}, "Add All"))
        {
            stringstream ss(dataInput);

            int i;

            while (ss >> i)
            {
                BubbleSort::insert(i);
                if (ss.peek() == ',')
                    ss.ignore();
            }

            array_filled = true;
        }
    }

    if (array_filled)
    {
        if (GuiButton(Rectangle{w - 190, 125, 170, 35}, "Sort"))
        {
            BubbleSort::startSorting();
        }
    }

    DrawText(codes, 20, h - 155, 10, WHITE);
}