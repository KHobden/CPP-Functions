// Calculator
// Kieran Hobden
// 24-Feb-'21

#include <iostream>
#include <functional>

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_num()
{
    int num{};

    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a number: ";
        std::cin >> num;

        if (std::cin.fail())
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

char get_operator()
{
    char op{};

    while (true)
    {
        std::cout << "Enter an operator (+, -, *, / or %): ";
        std::cin >> op;

        if (std::cin.fail() || (op != '+' && op != '-' && op != '*' && op != '/' && op != '%'))
        {
            std::cin.clear(); // Return std::cin to working condition
            ignore_line(); // Remove extraneous input
            std::cout << "That input is invalid. Try again.\n";
        }
        else
        {
            ignore_line();
            return op;
        }
    }
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    if (y == 0)
    {
        std::cerr << "Cannot divide by 0";
    }
    return x / y;
}

int modulus(int x, int y)
{
    return x % y;
}

using ArithmeticFunction = std::function<int(int, int)>;
ArithmeticFunction  getArithmeticFunction(char op)
{
    switch (op)
    {
    default: // Defaults to add
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
    case '%': return modulus;
    }
}

int main()
{
    int x{ get_num() };
    char op{ get_operator() };
    int y{ get_num() };
    
    ArithmeticFunction fcn{ getArithmeticFunction(op) };

    std::cout << x << op << y << '=' << fcn(x, y) << '\n';



    return 0;
}
