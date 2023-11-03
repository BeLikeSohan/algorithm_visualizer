#include <iostream>

#pragma once

class GUI
{
private:
    inline static bool array_created = false;
    inline static bool array_filled = false;

public:
    void drawStackUI(int height, int width);
    void drawBubbleSortUI(int height, int width);
};