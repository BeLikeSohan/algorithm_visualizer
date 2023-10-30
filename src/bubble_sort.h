#include <iostream>

#pragma once

class BubbleSort
{
public:
    inline static int size = 0;
    inline static int max_size = 0;
    inline static int array[64];
    inline static int i = 0;
    inline static int j = 0;
    inline static int frame_counter = 0;
    inline static bool running = true;
    static void create(int size_value);
    static void insert(int value);
    static void draw(int height, int width);
    static void drawSort(int height, int width);
};