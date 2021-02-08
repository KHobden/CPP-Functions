// Factorial
// Kieran Hobden
// 07-Feb-'21

// Generate the result of integer factorial for a number less than 20

#include "pch.h"
#include <iostream>

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

unsigned long long factorial(int num)
{
    if (num == 0) return 1;
    return num*factorial(num-1);
}

unsigned int get_num()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a number no larger than 20 to find its factorial: ";
        unsigned int num{}; // Number to find the factorial
        std::cin >> num;

        if (std::cin.fail() || num > 20)
        {
            std::cin.clear(); // Return std::cin to working condition
            ignore_line(); // Remove extraneous input
            std::cout << "That input is invalid. Try again.\n";
        }
        else
        {
            ignore_line();
            return num;
        }
    }
}

int main()
{
    unsigned int num{ get_num() };
    std::cout << num << "! = " << factorial(num);

    return 0;
}