#include <iostream>

#pragma once

class Stack
{
public:
    inline static int size = 0;
    inline static struct Node *stackHead;
    static void push(int data);
    static int pop();
    static int getSize();
    static void print();
    static void draw(int height, int width);
};