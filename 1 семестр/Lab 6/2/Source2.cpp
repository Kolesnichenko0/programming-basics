#include "SomeFile.h"
#include <cmath>
using namespace std;
// 1 ������ ��� ����������
double someFunct1(double x)
{
	return x * x * x;// ������� � � ���, �� ������� �� 3*x
}
// 2 ������� ��� ����������
double someFunct2(double x)
{
	return cbrt(x);// ������� � �� ������� ������, �� ������� �� (1/3) * (1/pow(x, -2/3 )) 
}

//�������� ������ �� �� ��������
bool ReadingData(float& start, float& step, float& end)
{
	cout << "����i�� ������� , ���� �� �i���� i��������:" << endl;
	cout << "start = ";
	cin >> start;
	cout << "step = ";
	cin >> step;
	cout << "end = ";
	cin >> end;
	if (start >= end || step <= 0)
	{
		if (start >= end)
		{
			cerr << "���i��i ���i, �� start < end " << endl;
		}
		if (step <= 0)
		{
			cerr << "���i��i ���i, �� step>0 " << endl;
		}
		return false;
	}

	return true;

}

int main()
{
	setlocale(LC_ALL, "UKR");
	float start, step, end;
	if (ReadingData(start, step, end))
	{
		cout << "�i�i������ �������� ������ ���i��� (�����i� 1): ";
		cout << findMinDerivativeValue (someFunct1, start, end, step) << endl;
		cout << "�i�i������ �������� ������ ���i��� (�����i� 2): " ;
		cout << findMinDerivativeValue (someFunct2, start, end, step) << endl;
		return 0;
	}
	return -1;
}
