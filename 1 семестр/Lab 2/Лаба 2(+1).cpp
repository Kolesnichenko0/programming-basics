//Завдання 1 , читання символів і виведення їх шістнадцяткових кодів.
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "UKR");
	char n;
	do
	{
		cout << "Введiть символ: " << endl;
		cin >> n;
		cout << "Шiстнадцятковий код: " << hex << int(n) << endl<<endl;
	} while (n != 'A');
	return 0;
}