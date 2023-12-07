#include <iostream>

#pragma once

class SelectionSort
{
public:
    inline static int size = 0;
    inline static int max_size = 0;
    inline static int array[64];
    inline static int i = 0;
    inline static int j = 0;
    inline static int frame_counter = 0;
    inline static bool running = false;
    inline static int state = 0;
    inline static int move_anim_state_a = 0;
    inline static int move_anim_state_b = 0;
    inline static int block_a_posx = 0, block_a_posy = 0;
    inline static int block_b_posx = 0, block_b_posy = 0;
    inline static int counter = 0;
    inline static int task_state = 0;
    inline static bool one_step = false;
    static void create(int size_value);
    static void insert(int value);
    static void draw(int height, int width);
    static void drawSort(int height, int width);
    static void startSorting();
    static void oneStep();
};