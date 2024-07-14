//Степені числа 8

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UKR");
	int a;
	while (true)
	{
		cout << "Введiть цiле число a у дiпозонi вiд 0 до 10:" << endl;
		cin >> a;
		if (a > 10 || a < 0)
		{
			cerr << "Невiрне значення а";
			break;
		}
		for (int i =0; i<=a;i++)
		{
			cout << "8 ^ " << i << " = " << (1 << 3*i) << endl;
		   }
		cout << endl;


		if (a == 0)
		{
			break;
		}
	}


	return 0;

}