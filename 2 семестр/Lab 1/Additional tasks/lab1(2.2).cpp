//Production of two numbers

#include <iostream>

struct Numbers {
    int a;
    int b;
};

//Calculating production of two numbers
int sqr(Numbers elems) {
    return elems.a * elems.b;
}

int main()
{
    Numbers elems;
    std::cout << "To calculate the product of two numbers"  << std::endl;
    std::cout << "Enter 2 numbers:" << std::endl;
    std::cout << "a = ";
    if (!(std::cin >> elems.a)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }
    std::cout << "b = ";
    if (!(std::cin >> elems.b)) { // Checking for value validity
        std::cerr << "Error: Invalid value\n";
        return 1;
    }
    std::cout << "Production of two numbers: " << sqr(elems) << std::endl;
}

