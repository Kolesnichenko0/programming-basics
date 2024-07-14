// Індивідуальне завдання
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <clocale>

using std::printf;


int main()
{

    std::setlocale(LC_ALL, "UKR");
    std::ifstream inFile("text.txt");
    int m, n;
    inFile >> m >> n;
    //створення і заповнення масиву
    int** a = new int* [m]; 
    for (int i = 0; i < m; i++) 
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            inFile >> a[i][j];
        }
    }
    // вивід початкового масиву
    printf("Початковий масив:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    // перевірка , чи можливе перетворення
    bool checking = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                checking = true;
            }
        }
    }
    std::ofstream outFile1("outFile1.txt");
    if (checking == false)
    {
        outFile1 << "У масивi немає парних чисел, тому перетворення неможливе";
        outFile1.close();
        printf("У масивi немає парних чисел, тому перетворення неможливе\n");
        return 0;
    }
    //перетворення елементів початкового масиву
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                a[i][j] = pow(a[i][j], 2);
            }
        }
    }
    // вивід масиву після першого кроку
    printf("Масив пiсля перетворення елементiв початкового масиву : \n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
            outFile1 << a[i][j] << '\t';
        }
        printf("\n");
        outFile1 << '\n';
    }
    outFile1.close();
    //створення одновимірного масиву та заповнення елементів
    double* b = new double [n]; 
    for (int i = 0; i < n; i++)
    {
        int Min = a[0][i];
        for (int j = 1; j < m; j++)
        {
            if (Min > a[j][i])
            {
                Min = a[j][i];
                double y = cbrt(a[j][i]);
                a[j][i] = cbrt(a[j][i]);
                *(b+i) = y;
            }

        }
        if (Min == a[0][i])
        {
            double h = cbrt(a[0][i]);
            a[0][i] = cbrt(a[0][i]);
            *(b+i) = h;
        }
    }
    std::ofstream outFile2("outFile2.txt");
    // вивід масиву після другого кроку
    printf("Масив пiсля заповнення елементiв масиву, який отримали пiсля першого кроку:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%.5lf\t", *(b + i));
        outFile2 << *(b + i) << '\t';
    }
    outFile2.close();
    //Звільнення пам'яті
    delete[] b; 
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}


