// Сума мінімального і максимального елементів
#define _CRT_SECURE_NO_WARNINGS
#include <clocale>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using std::srand;
using std::time;
using std::rand;
using std::scanf;
using std::printf;

double min(double* arr, int n)
{
    double Min = *arr;
    for (int i = 1; i < n; i++)
    {
        if (Min > *(arr+i))
        {
            Min = *(arr+i);
        }
    }
    return Min;
}

double max(double* arr, int n)
{
    double Max = *arr;
    for (int i = 1; i < n; i++)
    {
        if (Max < *(arr+i))
        {
            Max = *(arr+i);
        }
    }
    return Max;
}


int main()
{
    std::setlocale(LC_ALL, "UKR");
    int n;
    printf("Введiть довжину масиву:\n");
    scanf("%i", &n);
    if (n <= 0)
    {
        printf("Невiрна довжина масиву\n");
        return -1;
    }
    double *pArray =  new double[n];
    srand(time(0));
    printf("Навчальний масив:\n");
    for (int i = 0; i < n; i++)
    {
       *(pArray + i) = (rand() % 400 ) * 0.25;
       printf("%.2lf \t", *(pArray + i));
    }
    printf("\n");
    double sum = min(pArray, n) + max(pArray, n);
    printf("Сума мiнiмального i максимального значень елементiв масиву  = %.2lf", sum);
    delete[] pArray;
    return 0;
}
