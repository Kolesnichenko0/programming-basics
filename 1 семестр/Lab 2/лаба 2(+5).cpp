//Завдання 5.Читання дійсного x та обчислення y (математична функція signum) з використанням умовної операції
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
		int y = x < 0 ? -1 :( x == 0 ? 0 : 1);
		cout << "y = " << y << endl << endl;
	} while (x != 4);
	return 0;
}