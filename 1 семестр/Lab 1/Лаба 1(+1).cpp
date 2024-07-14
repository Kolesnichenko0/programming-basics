//Перевод дюймів у міліметри
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	float N, a;
	do
	{
		cout << "Введiть довжину у дюймах:" << endl;
		cin >> N;
		a = N * 25.4;
		cout << "Довжина в мiлiметрах:" << a << endl << endl;
	} while (N != 0);

	return 0;
}