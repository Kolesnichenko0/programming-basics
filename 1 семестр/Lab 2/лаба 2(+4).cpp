//Завдання 4.Читання дійсного x та обчислення y (математична функція signum) з використанням твердження if
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKR");
	double x;
	do
	{
		cout << "Введiть дiйсне х для обчислення значення функцiї:" << endl;
		cin >> x;
		if (x < 0)
		{
			cout << "y = -1" << endl << endl;
		}
		else
		{
			if (x == 0)
			{
				cout << "y = 0" << endl << endl;
			}
			else
			{
				cout << "y = 1" << endl << endl;
			}
		}
	} while (x != 4);
	return 0;
}