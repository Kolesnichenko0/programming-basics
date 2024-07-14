//Обчислення факторіалу
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	int n;
	do
	{
		cout << "Для розрахування n! введiть n :" << endl;
		cin >> n;
		int power = 1;
		for (int i = 1; i <= n; i++)
		{
			power = power * i;
		}
		cout << "n! = " << power << endl << endl;
	} while (n != 0);

	return 0;
}
