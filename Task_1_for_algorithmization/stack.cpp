//stack.cpp -- member function class stack
#include <iostream>
#include "stack.h"

Stack::Stack(int n)         //create empry stack
{
    top = 0;
    size = n;
    items = std::unique_ptr<Item []>(new Item(n));
    std::cout << "Hi! The stack whith size " << n
              << " element(s) was created." << std::endl;
}
Stack::~Stack()
{
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
        items[top++] = item;
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
        item = items[--top];
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
        size = n;
        return true;
    }
    else {
        std::cout << "Delete " << top - n << " element(s).\n";
        return false;
    }
}
