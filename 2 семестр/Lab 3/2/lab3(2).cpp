#include <iostream>
#include <cmath>
#include "Header.h"

//Class for calculating derivatives for the cube root function
class cubicRootFunction : public AbstractDerivative {
public:
    //Overridden pure virtual function of the base class
    virtual double someFunction(double x) override {
        return cbrt(x); //The cubic root function, its derivative is (1/3) * (1/pow(x, -2/3 )) 
    }
};

int main() {
    cubicRootFunction cbrtDerivative;
    std::cout << "The cubic root function:\n";
    std::cout << "The minimum value of the first derivative on the interval [1; 6] (step = 2): " << cbrtDerivative.findMinDerivative(1, 6, 2) << "\n";
    std::cout << "The minimum value of the first derivative on the interval [-5; 8] (step = 1): " << cbrtDerivative.findMinDerivative(-5, 8, 1) << "\n";
    return 0;
}
