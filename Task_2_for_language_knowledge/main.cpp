//Create recursive function which calculates sum of first n element of Fibonacci numberc
#include <iostream>

typedef unsigned long Item;

Item Fibonacci(int num);            //find n element of Fibonacci number
Item sumFibonacci(int num);         //calculates sum of first n element
int main()
{
    std::cout << "Enter the number element of Fibonacci number: ";
    int n;
    while(std::cin >> n)
    {
        std::cout << "The sum of first " << n << " element of Fibonacci number: "
                  << sumFibonacci(n) << std::endl;
        std::cout << "Please, next number: ";
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}

Item Fibonacci(int num)
{
    if(num == 0)                        //F0 = 0
        return 0;
    else if(num == 1 || num == 2)       //F1 = F2 = 1
    {
        return 1;
    }
    else
    {
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
}

Item sumFibonacci(int num)                  //recursive function
{
    Item sum = 0;
    sum += Fibonacci(num);
    if(num > 0)
        sum += sumFibonacci(num - 1);       //using recursion calling
    return sum;
}
