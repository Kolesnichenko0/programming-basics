//Using templates
#include "Header.h"
#include <iostream>
#include <math.h>

double cubicRootFunction(double x) {
    return cbrt(x); //The cubic root function, its derivative is (1/3) * (1/pow(x, -2/3 )) 
}

//Class for creating a functional object 
class cubicFunctionalObject {
public:
    //Overload the operation of a function call 
    double operator()(double x) {
        return pow(x,3); //The cubic function, its derivative is 3*x^2
    }
};


int main() {
    //Using a template function with the cubicRootFunction
    std::cout << "The cubic root function:\n";
    std::cout << "The minimum value of the first derivative on the interval [1; 6] (step = 2): " << findMinDerivative([](double x) {return cbrt(x); }, 1, 6, 2) << "\n\n";
    //Using a template function with the functional object cubicFunction
    cubicFunctionalObject cubicFunction;
    std::cout << "The cubic function:\n";
    std::cout << "The minimum value of the first derivative on the interval [1; 6] (step = 1): " << findMinDerivative(std::sin, 1, 6, 1) << "\n";
}

