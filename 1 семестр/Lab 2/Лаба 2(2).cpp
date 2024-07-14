//Розрахунок 1.2
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	float n, k, x;
	cout << "Для обчислення виразу введiть n, k, x:" << endl << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
	cout << "x = ";
	cin >> x;

	int t = trunc(n * 10);   //убирает дробную часть числа n*10
	int d = trunc(k * 10);   //убирает дробную часть числа k*10
	if (n < 1 || k < 1 || (t % 10) != 0 || (d % 10) != 0)
	{
		cout << "Невiрнi данi" << endl;
		return 0;
	}
	if (k > n)
	{
		cout << "Рохрахунок вiдбудеться без k" << endl;
	}
	float y = 0;
	int i = 1;
	if (i <= n)
	{
		for (i = 1; i <= n; i++)
		{
			if (i == k)
			{
				continue;
			}
			if (x == -2 * i)
			{
				cout << "X не належить областi визначень функцiї" << endl;
				return 0;
			}
			y = y + i / (x + 2 * i);
		}
		cout << "y = " << y << endl;
	}
	return 0;
}