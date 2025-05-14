#include "Stack.h"
#include "Vector.h"
#include <iostream>
using namespace std;

void Stack::clear()
{
    size = 0;
}

bool Stack::isEmpty() const
{    // return true if Stack is empty
    return (size == 0);
}

int Stack::pop()
{
    if (isEmpty())
    {
        return NULL;
    }
    else {
        int x = data[0];
        int* temp = new int[size - 1];
        for (int i = 1; i < size; i++)
            temp[i - 1] = data[i];
    
        for (int i = 0; i < size - 1; i++)
            data[i] = temp[i];
        size--;
        return x;
    }
         
}

void Stack::push(int val)
{
       insert(val);
}

int Stack::top() const
{
    if (isEmpty())
    {
        return NULL;
    }
    else
      return data[0];
}

Stack::~Stack()
{
    clear();
}
