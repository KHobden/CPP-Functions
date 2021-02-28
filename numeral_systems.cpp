// Numeral Systems
// Kieran Hobden
// 15-Feb-'21

#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_num(const int lower_lim)
// Get user inputted int
{
    while (true) // Loop until user enters a valid input
    {
        int num{};
        std::cin >> num;
        if (std::cin.fail() || num > INT_MAX || num < lower_lim)
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

int get_length(const int base, const int num)
// Returns the size of array needed to store the number
{
    if (num < 0 || base < 2)
    {
        std::cerr << "ERROR";
        // Introduce error handling for invalid num or base
        return -1;
    }
    else if (num == 0)
    {
        return 1; // Zero must be stored in array of size 1
    }
    else
    {
        return ceil(log(num + 1) / log(base));
    }
}

void convert(const int base, const int num, std::vector<int>& array)
// New_num in base is equivalent to num in base 10
{
    if (num < base)
    {
        array.push_back(num); // Count zero here
        return;
    }
    else
    {
        convert(base, num / base, array);
        array.push_back(num % base);
        return;
    }
}

int main()
{
    std::cout << "Enter a number greater than 1 to be the radix (base): ";
    int base{ get_num(2) }; // Number must be >=2

    std::cout << "To end, enter -1\n";

    while (true)
    {
        std::cout << "Enter a non-negative integer: ";
        int num{ get_num(-1) }; // Number must be >=0, -1 used for break

        if (num == -1)
        {
            std::cout << "---END---";
            break; // End loop if -1 entered
        }

        std::vector<int> new_num{}; // Initialise a vector for our new number
        convert(base, num, new_num); // Convert num into new base

        for (int element : new_num)
        {
            std::cout << element << ' ';
        }
        std::cout << '\n';

        new_num.clear();
    }


    /*
    int length{ get_length(base, num) }; // Length of array needed to store new number
    std::cout << "Length of array needed to store value: " << length << '\n';
    */

    return 0;
}