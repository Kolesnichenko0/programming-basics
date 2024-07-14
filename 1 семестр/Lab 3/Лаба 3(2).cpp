// Завдання 1.2 . Рекурсія.
#include <iostream>
using namespace std;

float product(int n, float x)
{
	if (n == 1)
	{
		return x + 1;
	}
	else
	{
		return (x + n) * product(n - 1, x);
	}
}

int main()
{
	setlocale(LC_ALL, "UKR");
	float n;
	cout << "Для обчислення введiть n, x " << endl<< "n = ";
	cin >> n;
	int d = trunc(n * 10);
	if (n < 1 || d % 10 != 0)
	{
		cout << "Невiрне значення n" << endl;
		return 0;
	}
	float x;
	cout << "x = ";
	cin >> x;

	cout << "y = " << product(n, x) << endl;
	return 0;
}