// Numeral Systems
// Kieran Hobden
// 15-Feb-'21

#include <iostream>
#include <cmath>

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_num(const int lower_lim)
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

int get_length(const int base, const int num) // Returns the size of array needed to store the number
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

int* in_numeral_system(const int base, const int num)
{
    static int count{ 0 }; // Count (length-num_of_recursions)
    static int length{ get_length(base, num) };
    static int* array{ new int[length] {} }; // Store result

    if (num < base)
    {
        array[0] = num; // Count zero here
        return array;
    }
    else
    {
        in_numeral_system(base, num / base);
        ++count;
        array[count] = num % base;
        return array;
    }
}

void print_array(const int *array, const int length)
{
    if (!array) return; // End function if passed null pointer

    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << array[i] << ' ';
    }
}

int main()
{
    std::cout << "Enter a number greater than 1 to be the radix (base): ";
    int base{ get_num(2) };
    std::cout << "Enter a non-negative integer: ";
    int num{ get_num(0) };

    int length{ get_length(base, num) }; // Length of array needed to store new number
    std::cout << "Length of array needed to store value: " << length << '\n';
    
    int* array{ in_numeral_system(base, num) };
    std::cout << num << " in base " << base << " is ";
    print_array(array, length); // array evaluates to a pointer

    std::cout << '\n';
    delete[] array; // De-allocate array

    return 0;
}