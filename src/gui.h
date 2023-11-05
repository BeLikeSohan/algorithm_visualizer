#include <iostream>

#pragma once

class GUI
{
private:
    inline static bool array_created = true;
    inline static bool array_filled = true;

public:
    inline static bool bubble_sort_onestep = false;
    void drawStackUI(int height, int width);
    void drawBubbleSortUI(int height, int width);
};