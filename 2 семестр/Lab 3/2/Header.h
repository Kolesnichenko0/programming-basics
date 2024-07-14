#ifndef HEADER_H
#define HEADER_H

class AbstractDerivative {
private:
	//Function for finding the derivative
	double findDerivative(double x, double eps = 0.00000001);
public:
	//A function for finding the minimum value from those values that were in a certain interval with a certain step
	double findMinDerivative(double start, double end, double step);
	//A pure virtual function
	double virtual someFunction(double x) = 0;
};

#endif
