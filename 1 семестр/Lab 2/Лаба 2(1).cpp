//Рохрахунок коренів квадратичного рівняння
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKR");
	float a, b, c;
	cout << "Нехай ax^2+bx+c=0 , для розв'язання даного рiвняння вкажiть a, b, c:" << endl << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	if (a == 0)
	{
		if (b != 0)
		{
			float x = -c / b;
			cout << "x = " << x << endl;
		}
		else
		{
			if (c == 0)
			{
				cout << "Рiвняння має безлiч коренiв, x - любе значення." << endl;
			}
			else
			{
				cout << "Рiвняння немає коренiв" << endl;
			}
		}
	}
	else
	{
		float D = b * b - 4 * a * c;
		if (D < 0)
		{
			cout << "Рiвняння немає коренiв" << endl;
		}
		else
		{
			float x1 = (-b + sqrt(D)) / (2 * a);
			float x2 = (-b - sqrt(D)) / (2 * a);
			if (x1 == x2)
			{
				cout << "x = " << x1 << endl;
			}
			else
			{
				cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
			}
		}
	}
}
