#include "SomeFile.h"
using namespace std;

//Введення данних та їх перевірка
bool ReadingData(float& start, float& step, float& end)
{
	cout << "Введiть початок , крок та кiнець iнтервалу:" << endl;
	cout << "start = ";
	cin >> start;
	cout << "step = ";
	cin >> step;
	cout << "end = ";
	cin >> end;
	if (start >= end || step <= 0 )
	{
		if (start >= end)
		{
			cerr << "Невiрнi данi, бо start < end " << endl;
		}
		if (step <= 0)
		{
			cerr << "Невiрнi данi, бо step>0 " << endl;
		}
		return false;
	}

	return true;

}
//Знаходження значення функції
float y(float x)
{
	int n = 3;
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
int main()
{
	setlocale(LC_ALL, "UKR");
	float start, step, end;
	if (ReadingData(start, step, end))
	{
		cout << "Функцiя y:" << endl;
		printValues(start, step, end, y);
		cout << "Функцiя sin:" << endl;
		printValues(start, step, end, sin);
		cout << "Функцiя cbrt:" << endl;
		printValues(start, step, end, cbrt);
		return 0;
	}
	return -1;
}
