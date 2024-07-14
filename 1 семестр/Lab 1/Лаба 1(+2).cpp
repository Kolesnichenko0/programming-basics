// Обчислення середнього арифметичного
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	float a, b, c, d, e, f, g, h, S;
	cout << "Введiть 8 значень для обчислення середнього арифметичного:" << endl;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	S = (a + b + c + d + e + f + g + h) / 8;
	cout << "Середнє арифметичне: " << S;
	return 0;
}