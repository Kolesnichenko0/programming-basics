// Завдання 1.4 . Квадратне рівняння .
#include <iostream>
using namespace std;

int solve(float a , float b, float c, float& x1 , float& x2)
{
	if (a == 0)
	{
		if (b != 0)
		{
			x1 = -c / b;
			return 1;
		}
		else
		{
			if (c == 0)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		float D = b * b - 4 * a * c;
		if (D < 0)
		{
			return 0;
		}
		else
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			if (x1 == x2)
			{
				x1 == x2;
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "UKR");
	float a, b, c, x1, x2;
	cout << "Нехай ax^2+bx+c=0 , для розв'язання даного рiвняння вкажiть a, b, c:" << endl << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	int count = solve(a, b, c, x1, x2);
	switch (count)
	{
	case -1:
		cout << "Рiвняння має безлiч коренiв." << endl;
		break;
	case 0:
		cout << "Рiвняння немає коренiв" << endl;
		break;
	case 1:
		cout << "x = " << x1 << endl;
		break;
	case 2:
		cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		break;
	}
	return 0;
}