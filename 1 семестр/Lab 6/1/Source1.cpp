#include "SomeFile.h"
#include <cmath>
// Print ������� ������� ������� , ��� ��������� � �� ������� � ���������� ������
void printValues(float start, float step, float end, funcType functSolving)
{
	for (float x = start; x <= end; x += step)
	{
		std::cout << "x = " << x << " y = " << functSolving(x) << std::endl;
	}
}