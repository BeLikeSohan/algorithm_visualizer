#include <iostream>

#pragma once

class Stack
{
private:
    int size = 0;
    struct Node *stackHead = NULL;

public:
    void push(int data);
    int pop();
    int getSize();
    void print();
    void draw(int height, int width);
};