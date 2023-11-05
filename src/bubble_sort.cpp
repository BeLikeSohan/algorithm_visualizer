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

    DrawRectangle(30 + 60 * i, h + 10, 50, 50, ORANGE);
    DrawText(TextFormat("%d", array[i]), 30 + 60 * i, h + 10, 20, WHITE);

    DrawRectangle(30 + 60 * j, h + 10, 50, 50, ORANGE);
    DrawText(TextFormat("%d", array[j]), 30 + 60 * j, h + 10, 20, WHITE);

    if (!running)
    {
        if (max_size > 0)
        {
            if (size < max_size)
            {
                DrawText(TextFormat("Array Size: %d / %d", size, max_size), 20, 30, 30, WHITE);
            }
            else
            {
                DrawText(TextFormat("Array Size: %d / %d", size, max_size), 20, 30, 30, RED);
            }
        }
    }
    else
    {
        if (array[i] <= array[j])
        {
            DrawText(TextFormat("Comparing %d with %d", array[i], array[j]), 20, 30, 30, WHITE);
        }
        else
        {
            DrawText(TextFormat("Swapping %d with %d", array[i], array[j]), 20, 30, 30, WHITE);
        }
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

    int h = (height / 2) - 100;
    int w = (width / 2) - 150;

    switch (state)
    {
    case 0:
        DrawRectangle(30 + 60 * i, h + 10, 50, 50, ORANGE);
        DrawRectangle(30 + 60 * j, h + 10, 50, 50, ORANGE);
        DrawText(TextFormat("%d", array[i]), 30 + 60 * i, h + 10, 20, WHITE);
        DrawText(TextFormat("%d", array[j]), 30 + 60 * j, h + 10, 20, WHITE);
        state = 1;
        break;

    case 1:
        DrawRectangle((30 + 60 * i) + block_a_posx, (h + 10) + block_a_posy, 50, 50, ORANGE);
        DrawRectangle((30 + 60 * j) + block_b_posx, (h + 10) + block_b_posy, 50, 50, RED);
        DrawText(TextFormat("%d", array[i]), (30 + 60 * i) + block_a_posx, (h + 10) + block_a_posy, 20, WHITE);
        DrawText(TextFormat("%d", array[j]), (30 + 60 * j) + block_b_posx, (h + 10) + block_b_posy, 20, WHITE);

        // if (i == j)
        // {
        //     state = 2;
        // }

        if (array[i] <= array[j])
        {
            state = 3;
            break;
        }

        if (block_a_posy < 100 && move_anim_state_a == 0)
        {
            block_a_posy += 10;
            if (block_a_posy >= 100)
            {
                move_anim_state_a = 1;
            }
        }
        else if (move_anim_state_a == 1)
        {
            if (block_a_posx > (30 + 60 * j) - (30 + 60 * i))
            {
                block_a_posx -= 10;
            }
            else if (block_a_posx < (30 + 60 * j) - (30 + 60 * i))
            {
                block_a_posx += 10;
            }
            else
            {
                move_anim_state_a = 2;
            }
        }
        else if (block_a_posy > 0 && move_anim_state_a == 2)
        {
            block_a_posy -= 10;
            if (block_a_posy == 0)
            {
                move_anim_state_a = 3;
            }
        }

        // MOVE BLOCK B
        if (block_b_posy > -100 && move_anim_state_b == 0)
        {
            block_b_posy -= 10;
            if (block_b_posy <= -100)
            {
                move_anim_state_b = 1;
            }
        }
        else if (move_anim_state_b == 1)
        {
            cout << block_b_posx << " " << (30 + 60 * i) - (30 + 60 * j) << endl;

            // if (block_b_posx > (30 + 60 * i) - (30 + 60 * j))
            // {

            //     block_b_posx = (30 + 60 * i) - ((30 + 60 * j));
            //     move_anim_state_b = 2;
            // }
            // else
            // {
            //     block_b_posx += 10;
            // }

            if (block_b_posx > (30 + 60 * i) - (30 + 60 * j))
            {
                block_b_posx -= 10;
            }
            else if (block_b_posx < (30 + 60 * i) - (30 + 60 * j))
            {
                block_b_posx += 10;
            }
            else
            {
                // block_b_posx += 10;
                move_anim_state_b = 2;
            }
        }
        else if (block_b_posy >= -100 && move_anim_state_b == 2)
        {
            if (block_b_posy == 0)
            {
                move_anim_state_b = 3;
            }
            else
            {
                block_b_posy += 10;
            }
        }

        if (move_anim_state_b == 3)
        {
            state = 2;
            move_anim_state_a = 0;
            move_anim_state_b = 0;
            block_a_posx = 0;
            block_a_posy = 0;
            block_b_posx = 0;
            block_b_posy = 0;

            if (one_step)
            {
                one_step = false;
                running = false;
            }
        }
        break;

    case 2:
        frame_counter++;
        if (frame_counter % 2 == 0)
            return;

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

        state = 0;
        break;

    case 3:
        DrawRectangle((30 + 60 * i) + block_a_posx, (h + 10) + block_a_posy, 50, 50, ORANGE);
        DrawRectangle((30 + 60 * j) + block_b_posx, (h + 10) + block_b_posy, 50, 50, ORANGE);
        DrawText(TextFormat("%d", array[i]), (30 + 60 * i) + block_a_posx, (h + 10) + block_a_posy, 20, WHITE);
        DrawText(TextFormat("%d", array[j]), (30 + 60 * j) + block_b_posx, (h + 10) + block_b_posy, 20, WHITE);
        counter++;
        if (counter > 5)
        {
            counter = 0;
            state = 2;
            break;
        }
    }
}

void BubbleSort::startSorting()
{
    running = true;
}

void BubbleSort::oneStep()
{
    running = true;
    one_step = true;
}