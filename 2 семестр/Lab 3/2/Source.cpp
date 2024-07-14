#include "Header.h"

//Function that calculates the value of the first derivative
double AbstractDerivative::findDerivative(double x, double eps)
{
	return (someFunction(x + eps) - someFunction(x)) / eps;
}

//Function that calculates the minimum value from those values that were on the specified interval with a certain step
double AbstractDerivative::findMinDerivative(double start, double end, double step)
{
	double min = findDerivative(start);
	for (double x = start + step; x <= end; x += step)
	{
		if (min > findDerivative(x))
		{
			min = findDerivative(x);
		}
	}
	return min;
}
