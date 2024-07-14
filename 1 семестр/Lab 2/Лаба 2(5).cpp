//Обчислення індивідуального завдання 16
#include <iostream>
using namespace std;



int main()
{
	setlocale(LC_ALL, "UKR");
	float a, b, h;
	int n;
	cout << "Введiть a, b, h, n:" << endl << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "h = ";
	cin >> h;
	cout << "n = ";
	cin >> n;
	float x = a;
	if (x > b)
	{
		cout << "Невiрнi данi, бо a>b " << endl;
		return 0;
	}
	if (h <= 0)
	{
		cout << "Невiрнi данi, бо h<=0, тому програма нiколи не закiнчиться " << endl;
		return 0;
	}
	if (n < 1)
	{
		cout << "Невiрнi данi, бо повинно бути n>=1 " << endl;
		return 0;
	}
	while (x <= b)
	{
		if (x > 0)
		{
			float y = 0;
			for (int i = 0; i <= n - 1; i++)
			{
				for (int j = 0; j <= n - 1; j++)
				{
					y = y + (x + j) / (i + j + 1);
				}
			}
			cout << "y = " << y << " x = " << x << endl;
		}
		else
		{
			float y = 1;
			for (int i = 0; i <= n - 1; i++)
			{
				y = y * (x + i);
			}
			cout << "y = " << y << " x = " << x << endl;
		}
		x = x + h;
	}
	return 0;
}