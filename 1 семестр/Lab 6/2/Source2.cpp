#include "SomeFile.h"
#include <cmath>
using namespace std;
// 1 фунція для тестування
double someFunct1(double x)
{
	return x * x * x;// Функція х в кубі, її похідна це 3*x
}
// 2 функція для тестування
double someFunct2(double x)
{
	return cbrt(x);// Функція х під кубічним корнем, її похідна це (1/3) * (1/pow(x, -2/3 )) 
}

//Введення данних та їх перевірка
bool ReadingData(float& start, float& step, float& end)
{
	cout << "Введiть початок , крок та кiнець iнтервалу:" << endl;
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
			cerr << "Невiрнi данi, бо start < end " << endl;
		}
		if (step <= 0)
		{
			cerr << "Невiрнi данi, бо step>0 " << endl;
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
		cout << "Мiнiмальне значення першой похiдної (Функцiя 1): ";
		cout << findMinDerivativeValue (someFunct1, start, end, step) << endl;
		cout << "Мiнiмальне значення першой похiдної (Функцiя 2): " ;
		cout << findMinDerivativeValue (someFunct2, start, end, step) << endl;
		return 0;
	}
	return -1;
}
