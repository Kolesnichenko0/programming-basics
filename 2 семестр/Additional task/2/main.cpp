//Колесниченко Денис Євгенович, КН-222б
import std;
import MinDerivative;

#include <math.h>

int main() {
    std::cout << "For the cubic function:\n";
    std::cout << "The minimum value of the first derivative on the interval [1; 6] (step = 2): " 
        << findMinDerivative([](double x) {return pow(x, 3); }, 1, 6, 2) << "\n\n";

    std::cout << "For the cubic root function:\n";
    std::cout << "The minimum value of the first derivative on the interval [1; 6] (step = 1): "
        << findMinDerivative([](double x) {return cbrt(x); }, 1, 6, 1) << "\n";
    return 0;
}

