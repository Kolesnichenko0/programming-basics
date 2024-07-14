#include "SomeFile.h"
//������� �������� ����� �������
double findDerivative(funcType funct, double x, double eps)
{
	return (funct(x + eps) - funct(x)) / eps;
}
// ������� �������� �������� � ��� �������, �� ���� �� ����������� �������� � ������ ������
double findMinDerivativeValue(funcType funct, double start, double end, double step)
{
	double min = findDerivative(funct, start);
	for (double x = start + step; x <= end; x += step)
	{
		if (min > findDerivative(funct, x))
		{
			min = findDerivative(funct, x);
		}
	}
	return min;
}