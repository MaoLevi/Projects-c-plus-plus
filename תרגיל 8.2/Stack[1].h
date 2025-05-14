#pragma once
#include "Vector.h"
class Stack:public Vector
{

public:
    void clear();
    bool isEmpty() const;
    int pop();
    void push(int value);
    int top() const;
    ~Stack(); 

};
