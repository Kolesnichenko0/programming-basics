// Сума мінімального і максимального елементів
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

double min(double a[], int n)
{
    double Min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (Min > a[i])
        {
            Min = a[i];
        }
   }
    return Min;
}

double max(double a[], int n)
{
    double Max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (Max < a[i])
        {
            Max = a[i];
        }
    }
    return Max;
}


int main()
{
    setlocale(LC_ALL, "UKR");
    const int n = 7;
    double a[n];
    srand(time(0));
    cout << "Навчальний масив:" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % 40 -20)* 0.75;
        cout << a[i] << "  ";
    }
    cout << endl;
    double sum = min(a, n) + max(a, n);
    cout << "Сума мiнiмального i максимального значень елементiв масиву  = " << sum << endl;
    return 0;
}
