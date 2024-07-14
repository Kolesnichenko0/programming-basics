//Завдання 1.3 . Аргументи з усталеними значеннями. Перевантаження імен.
#include <iostream>
using namespace std;
float production(float a2 = 1, float a3 = 1, float a4 = 1 )
{
	return a2 * a3 * a4;
}

int production_overload(int a1 = 1)
{
	return a1;
}
float production_overload(float a2)
{
	return a2;
}
float production_overload(float a2, float a3)
{
	return a2 * a3;
}
float production_overload(float a2, float a3, float a4)
{
	return a2 * a3 * a4;
}


int main()
{
	setlocale(LC_ALL, "UKR");
	cout << "Реалiзування з усталеними значеннями аргументiв:" << endl;
	cout << "Значення функцiї = 1 : " << endl << production() << endl;
	cout << "Значення функцiї - аргумент  : " << endl << production(2) << endl;
	cout << "Значення функцiї - добуток 2 аргументiв  : " << endl << production(2, 5.2) << endl;
	cout << "Значення функцiї - добуток 3 аргументiв  : " << endl << production(4, 5, 5.2) << endl;
	cout << "Реалiзування за допомогою перевантаження iмен:" << endl;
	cout << "Значення функцiї = 1 : " << endl << production_overload() << endl;
	cout << "Значення функцiї - аргумент  : " << endl << production_overload(5) << endl;
	cout << "Значення функцiї - добуток 2 аргументiв  : " << endl << production_overload(4.2, 6) << endl;
	cout << "Значення функцiї - добуток 3 аргументiв  : " << endl << production_overload(5, 6, 2.4) << endl;

	return 0;
}