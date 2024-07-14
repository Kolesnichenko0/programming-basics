// Завдання 1.5 . Індивідуальне завдання
#include <iostream>
using namespace std;

//Введення данних та їх перевірка
bool ReadingData(float& start, float& step, float& end, int& n)
{
	setlocale(LC_ALL, "UKR");
	cout << "Введiть початок , крок, кiнець iнтервалу та n :" << endl;
	cout << "start = ";
	cin >> start;
	cout << "step = ";
	cin >> step;
	cout << "end = ";
	cin >> end;
	cout << "n = ";
	cin >> n;
	if (start >= end || step <= 0 || n < 1)
	{
		if (start >= end)
		{
			cerr << "Невiрнi данi, бо start >= end " << endl;
		}
		if (step <= 0)
		{
			cerr << "Невiрнi данi, бо step<=0, тому програма нiколи не закiнчиться " << endl;
		}
		if (n < 1)
		{
			cerr << "Невiрнi данi, бо повинно бути n>=1 " << endl;
		}
		return false;
	}
	
	return true;
    
}
//Знаходження значення функції
float y(float x, int n)
{
	if (x > 0)
	{
		float y = 0;
		for (int i = 0; i <= n - 1; i++)
		{
			for (int j = 0; j <= n - 1; j++)
			{
				y = y + (x + j) / (i + j + 1);
			}
		}
		return y;
	}
	else
	{
		float y = 1;
		for (int i = 0; i <= n - 1; i++)
		{
			y = y * (x + i);
		}
		return y;
	}

}
// Print шуканих значень функції , при відповідних х на ітервалі з визначеним кроком
void printValues(float start, float step, float end , int n)
{
	for (float x = start; x <= end; x += step)
	{
		cout << "x = " << x << " y = " << y(x, n) << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "UKR");
	float start, step, end;
	int n;
	if (ReadingData(start, step, end, n))
	{
		printValues(start, step, end, n);
		return 0;
	}
	return -1;
}

