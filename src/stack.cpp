#include <iostream>
#include <sstream>
#include <raylib.h>
#include "raygui.h"
#include "stack.h"

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void Stack::push(int data)
{
    if (stackHead == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        stackHead = newNode;
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = stackHead;
        stackHead = newNode;
    }

    size++;
}

int Stack::pop()
{
    struct Node *tempNode = stackHead;
    int data = stackHead->data;
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
    int arr[arrSize];
    struct Node *tempNode = stackHead;
    int index = 0;
    while (tempNode != NULL)
    {
        arr[index] = tempNode->data;
        index++;
        tempNode = tempNode->next;
    }

    int posX = (width / 2) - 130, posY = 35;

    DrawRectangleLines(posX, posY, 70, height - 230, GREEN);

    for (int i = arrSize - 1; i >= 0; i--)
    {
        int y = height - 245 - (60 * (arrSize - i - 1));

        DrawRectangle(posX + 10, y - 10, 50, 50, BLUE);

        DrawText(TextFormat("%d", arr[i]), posX + 15, y - 10, 20, ORANGE);
    }
}