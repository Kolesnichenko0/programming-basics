// Сортування за зменшенням
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    setlocale(LC_ALL, "UKR");
    const int n=5;
    int a[n];
    srand(time(0));
    cout << "Начальний масив:" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 40 - 20;
        cout << a[i] << "  ";
    }
    cout << endl;

    bool sort;
    do
    {
        sort = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i+1] > a[i])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sort = true;
            }
        }

    } while (sort);
    cout << "Значення за зменшенням: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

}

