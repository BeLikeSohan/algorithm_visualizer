#include <iostream>
#include <sstream>
#include <string.h>
#include <raylib.h>
#include "raygui.h"
#include "stack.h"

using namespace std;

struct Node
{
    char data[64];
    struct Node *next;
};

void Stack::push(char *data)
{
    if (stackHead == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->data, data);
        newNode->next = NULL;
        stackHead = newNode;
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->data, data);
        newNode->next = stackHead;
        stackHead = newNode;
    }

    size++;
}

char *Stack::pop()
{
    struct Node *tempNode = stackHead;
    char *data = stackHead->data;
    stackHead = stackHead->next;

    free(tempNode);

    size--;

    return data;
}

int Stack::getSize()
{
    return size;
}

void Stack::print()
{
    struct Node *tempNode = stackHead;

    while (tempNode != NULL)
    {
        cout << "-> " << tempNode->data << endl;
        tempNode = tempNode->next;
    }
}

void Stack::draw(int height, int width)
{
    int arrSize = size;
    char *arr[arrSize];
    struct Node *tempNode = stackHead;
    int index = 0;
    while (tempNode != NULL)
    {
        arr[index] = tempNode->data;
        index++;
        tempNode = tempNode->next;
    }

    int posX = (width / 2) - 130, posY = 35;

    DrawRectangleLines(posX, posY, 70, height - 230, WHITE);

    for (int i = arrSize - 1; i >= 0; i--)
    {
        int y = height - 245 - (60 * (arrSize - i - 1));

        DrawRectangle(posX + 10, y - 10, 50, 50, BLUE);

        DrawText(TextFormat("%s", arr[i]), posX + 15, y - 10, 20, ORANGE);

        if (i == 0)
        {
            DrawText("<-- HEAD", posX + 75, y, 30, WHITE);
        }

        if (i == arrSize - 1)
        {
            DrawText("TAIL -->", posX - 130, y, 30, WHITE);
        }
    }
}