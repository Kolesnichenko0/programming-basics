//Обчислення добутку 1.3
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKR");
	float x, n;
	cout << "Введiть значення x, n:" << endl << "x = ";
	cin >> x;
	cout << "n = ";
	cin >> n;
	int t = trunc(n * 10);   //убирает дробную часть числа n*10
	if (n < 1 || (t % 10) != 0)
	{
		cout << "Невiрнi данi" << endl;
		return 0;
	}
	float y = 1;
	int p = 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (x == -p * i)
		{
			y = 0;
			cout << "y = " << y << '\n';
			return 0;
		}
		y = y * (x + p * i);
		p = -p;
	}
	cout << "y = " << y << '\n';
	return 0;
}