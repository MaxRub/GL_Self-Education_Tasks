#include <iostream>
#include "stack.h"

int main()
{
    std::cout << "Enter the size of new stack: ";
    int n;
    std::cin >> n;
    Stack A(n);
    for(int i = n; i > 0; i--)
        A.push(i + 10);
    std::cout << "The capacity of stack is " << A._capacity()
              << " element(s)." << std::endl;
    std::cout << "The size of stack is " << A._size()
              << " element(s)." << std::endl;
    while(A._capacity())
    {
        int n;
        std::cout << "Element " << A._capacity();
        A.pop(n);
        std::cout << " is: " << n << std::endl;
    }
    std::cout << "Entre new size of stack: ";
    std::cin >> n;
    A._resize(n);
    for(int i = n; i > 0; )
    {
        A.push(i);
        i /= 2;
    }
    std::cout << "The capacity of stack is " << A._capacity()
              << " element(s)." << std::endl;
    std::cout << "The size of stack is " << A._size()
              << " element(s)." << std::endl;
    while(A._capacity())
    {
        int n;
        std::cout << "Element " << A._capacity();
        A.pop(n);
        std::cout << " is: " << n << std::endl;
    }
    return 0;
}
