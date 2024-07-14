//Завдання 2 , читання десяткових цілих чисел і друкування символів з відповідними кодами.
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "UKR");
	int n;
	do {
		cout << "Введiть десяткове цiле число: " << endl;
		cin >> n;
		cout << "Символ: " << dec << char(n) << endl << endl;
	} while (n != 0);
	return 0;
}