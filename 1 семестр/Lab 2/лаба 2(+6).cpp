//Завдання 6. Читання цілого n та обчислення y відповідно до таблиці
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKR");
	int n, y;
	do
	{
		cout << "Введiть цiле n для обчислення y:" << endl;
		cin >> n;
		switch (n)
		{
		case 0:
			y = 2;
			break;
		case 1:
			y = 4;
			break;
		case 2:
			y = 5;
			break;
		case 3:
			y = 3;
			break;
		case 4:
			y = 1;
			break;
		default:
			y = 0;
			break;
		}
		cout << "y = " << y << endl << endl;
	} while (n != 5);

}