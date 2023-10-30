#include <iostream>
#include <sstream>
#include <string.h>
#include <raylib.h>
#include "raygui.h"
#include "bubble_sort.h"

using namespace std;

void BubbleSort::insert(int value)
{
    array[size] = value;
    size++;
}

void BubbleSort::create(int size_value)
{
    max_size = size_value;
}

void BubbleSort::draw(int height, int width)
{
    int h = (height / 2) - 100;
    int w = (width / 2) - 150;

    DrawRectangleLines(20, h, (60 * max_size) + 10, 70, WHITE);

    for (int i = 0; i < size; i++)
    {
        DrawRectangle(30 + 60 * i, h + 10, 50, 50, BLUE);
        DrawText(TextFormat("%d", array[i]), 30 + 60 * i, h + 10, 20, WHITE);
    }
}

void BubbleSort::drawSort(int height, int width)
{
    if (!running)
        return;

    if (j >= size)
    {
        running = false;
    }

    cout << ":: i = " << i << " j = " << j << " size = " << size << endl;

    frame_counter++;
    if (frame_counter % 2 == 0)
        return;

    int h = (height / 2) - 100;
    int w = (width / 2) - 150;

    DrawRectangle(30 + 60 * i, h + 10, 50, 50, ORANGE);
    DrawRectangle(30 + 60 * j, h + 10, 50, 50, ORANGE);
    DrawText(TextFormat("%d", array[i]), 30 + 60 * i, h + 10, 20, WHITE);
    DrawText(TextFormat("%d", array[j]), 30 + 60 * j, h + 10, 20, WHITE);

    if (array[i] > array[j])
    {
        swap(array[i], array[j]);
    }

    i++;
    if (i >= size)
    {
        j++;
        i = 0;
    }
}