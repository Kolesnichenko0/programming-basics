//Завдання 1.1 . Статичні локальні змінні
#include <iostream>
using namespace std;
float a;
void min_max()
{
	setlocale(LC_ALL, "UKR");
	cout << "Введiть цiле число:" << endl;
    cin >> a;
	int d = trunc(a * 10);
	if (d%10 != 0) {
		cout << "Читайте уважнiше!!!" << endl;
		return;
	}
	static int min = a;
	static int max = a;
	if (a > max) {
		max = a;
	}
	if (a < min) {
		min = a;
	}
	cout << "Min = " << min << " Max = " << max << endl << endl;
}

int main()
{
	while (true)
	{
		min_max();
		if (a == 0)
		{
			break;
		}
	}
	return 0;
	
}