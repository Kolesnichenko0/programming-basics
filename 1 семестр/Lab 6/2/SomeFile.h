#ifndef SomeFile_h
#define SomeFile_h
#include <iostream>
typedef double (*funcType)(double);
double findDerivative(funcType funct, double x, double eps = 0.00000001);
double findMinDerivativeValue(funcType funct, double start, double end, double step);
#endif