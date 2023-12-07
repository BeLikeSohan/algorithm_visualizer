#include <iostream>

#pragma once

class GUI
{
private:
    inline static bool selection_sort_array_created = false;
    inline static bool selection_sort_array_filled = false;
    inline static bool bubble_sort_array_created = false;
    inline static bool bubble_sort_array_filled = false;

public:
    inline static bool selection_sort_onestep = false;
    inline static bool bubble_sort_onestep = false;
    inline static int currentSceneId = 0;
    void drawStackUI(int height, int width);
    void drawSelectionSortUI(int height, int width);
    void drawBubbleSortUI(int height, int width);
};