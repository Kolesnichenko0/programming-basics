#include "SomeFile.h"
using namespace std;

//�������� ������ �� �� ��������
bool ReadingData(float& start, float& step, float& end)
{
	cout << "����i�� ������� , ���� �� �i���� i��������:" << endl;
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
			cerr << "���i��i ���i, �� start < end " << endl;
		}
		if (step <= 0)
		{
			cerr << "���i��i ���i, �� step>0 " << endl;
		}
		return false;
	}

	return true;

}
//����������� �������� �������
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
		cout << "�����i� y:" << endl;
		printValues(start, step, end, y);
		cout << "�����i� sin:" << endl;
		printValues(start, step, end, sin);
		cout << "�����i� cbrt:" << endl;
		printValues(start, step, end, cbrt);
		return 0;
	}
	return -1;
}
