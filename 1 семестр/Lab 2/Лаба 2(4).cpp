//Обчислення суми 1.4
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKR");
	cout << "Для обчислення виразу введiть eps:" << endl;
	double eps;
	cin >> eps;
	double y = 0;
	if (eps > 0 && eps < 0.5)
	{
		for (double i = 0.5; i > eps; i = i * 0.5)
		{
			y = y + i;
		}
		cout << "y = " << y << endl;
	}
	else
	{
		cout << "Невiрнi данi" << endl;
	}
	return 0;
}