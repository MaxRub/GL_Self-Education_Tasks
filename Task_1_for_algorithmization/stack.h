//stack.h -- defining the stack class
#ifndef STACK_H
#define STACK_H

//using array
typedef int Item;

class Stack
{
private:
    Item * items;           //pointer to array of elements int
    int top;                //index the top of stack
    int size;               //maximum emount of elements
public:
    Stack(int n);           //cteate stack with number of elements
    ~Stack();
    bool isempty() const;
    bool isfull() const;

    //push() return false if stack is full, and true - in other way
    bool push(const Item & item);   //add element to stack

    //pop() return false if stack is empty, and true - otherwise
    bool pop(Item & item);

    //capacity() return amount of elements in stack;
    int _capacity() const;

    //size() return maximum amount of elements
    int _size() const;

    //resize() increase/decrease size of stack
    bool _resize(int n);
};

#endif // STACK_H
