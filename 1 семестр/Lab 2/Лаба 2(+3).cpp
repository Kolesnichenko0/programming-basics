//Вправа 3. Зчитування значення з рухомою крапкою і вивід округлене значення через round(n)
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "UKR");
	double n;
	do
	{
		cout << "Введiть значення для обчислення округлення значення:" << endl;
		cin >> n;
		cout << "Округлене значення:" << round(n) << endl << endl;
	} while (n != 0);
}