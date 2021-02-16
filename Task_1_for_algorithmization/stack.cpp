//stack.cpp -- member function class stack
#include <iostream>
#include "stack.h"

Stack::Stack(int n = 0)         //create empry stack
{
    top = 0;
    size = n;
    items = new Item[n];
    std::cout << "Hi! The stack whith size " << n
              << " element(s) was created." << std::endl;
}
Stack::~Stack()
{
    delete [] items;
    std::cout << "Bye!" << std::endl;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if(top < size)
    {
        *(items + (top++)) = item;
        return true;
    }
    else {
        return false;
    }
}

bool Stack::pop(Item & item)
{
    if(top > 0)
    {
        item = *(items + (--top));
        return true;
    }
    else {
        return false;
    }
}

int Stack::_capacity() const
{
    return top;
}

int Stack::_size() const
{
    return size;
}

bool Stack::_resize(int n)
{
    if(n > top)
    {
        Item * temp = new Item[n];
        for(int i = 0; i < top; i++)
        {
            *(temp + i) = *(items + i);
        }
        delete [] items;
        items = temp;
        size = n;
        return true;
    }
    else {
        std::cout << "Dlete " << top - n << " element(s).\n";
        return false;
    }
}
